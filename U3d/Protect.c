/*************************************************
* 功能：变压器差动保护 + 电流保护（速断/过流） + 电压保护（过压/欠压） + 阻抗保护（距离保护）
* 特性：模块化设计、真有效值计算、比率制动、二次谐波闭锁、自主编程扩展、保护出口逻辑
**************************************************/
#include <stdio.h>
#include <math.h>
#include <stdint.h>
/************************ 全局配置宏定义 ************************/
// 采样参数
#define  SAMPLE_POINT    32      // 每周波采样点数（50Hz，采样频率1600Hz）
#define  PI              3.1415926f  // 圆周率
#define  FREQ            50.0f   // 系统频率（Hz）
// 电流保护定值（单位：A）
#define  I_SD_SET        5.0f    // 电流速断整定值
#define  I_OC_SET        1.2f    // 过流保护整定值
#define  T_OC_SET        2.0f    // 过流动作延时（s）
#define  I_ZERO_SET      0.5f    // 零序电流整定值（可选）
// 电压保护定值（单位：V）
#define  U_OV_SET        120.0f  // 过压整定值（线电压）
#define  U_UV_SET        80.0f   // 欠压整定值（线电压）
#define  T_OV_SET        1.0f    // 过压动作延时（s）
#define  T_UV_SET        0.5f    // 欠压动作延时（s）
#define  U_ZERO_SET      10.0f   // 零序电压整定值（可选）
// 阻抗保护定值（单位：Ω）
#define  Z_SET           10.0f   // 阻抗整定值（距离保护Ⅰ段）
#define  Z_SLOPE         0.3f    // 阻抗保护斜率
#define  T_Z_SET         0.1f    // 阻抗保护动作延时（s）
// 变压器差动保护定值
#define  DIFF_START      0.2f    // 差动启动电流基准（A）
#define  RATIO_SLOPE     0.5f    // 比率制动斜率
#define  HARM_THRESH     0.15f   // 二次谐波制动系数门槛（防止励磁涌流误动）
#define  BALANCE_K       0.98f   // 变压器高低压侧平衡系数
// 保护出口定义（可映射到GPIO）
#define  TRIP_OUT        0x01    // 跳闸出口
#define  ALARM_OUT       0x02    // 告警出口
/************************ 数据结构定义 ************************/
// 三相电流/电压结构体（采样值/有效值）
typedef struct
{
    float A;  // A相
    float B;  // B相
    float C;  // C相
}ThreePhase;
// 变压器高低压侧电流结构体
typedef struct
{
    ThreePhase highSide;  // 高压侧三相电流
    ThreePhase lowSide;   // 低压侧三相电流
}TransCurr;
// 差动保护计算数据结构体
typedef struct
{
    float diff_A;    // A相差流（A）
    float diff_B;    // B相差流（A）
    float diff_C;    // C相差流（A）
    float restrain_A;// A相制动电流（A）
    float restrain_B;// B相制动电流（A）
    float restrain_C;// C相制动电流（A）
    float harm2_A;   // A相二次谐波含量
    float harm2_B;   // B相二次谐波含量
    float harm2_C;   // C相二次谐波含量
}DiffProtectData;
// 阻抗保护计算数据结构体
typedef struct
{
    float Z_A;       // A相阻抗值（Ω）
    float Z_B;       // B相阻抗值（Ω）
    float Z_C;       // C相阻抗值（Ω）
    float Z_angle_A; // A相阻抗角（°）
    float Z_angle_B; // B相阻抗角（°）
    float Z_angle_C; // C相阻抗角（°）
}ImpedanceData;
// 保护动作状态
typedef enum
{
    PROT_NORMAL = 0,    // 正常运行
    PROT_ALARM,         // 告警（越限未达到跳闸条件）
    PROT_TRIP           // 跳闸（满足动作条件）
}ProtState;
// 综合保护动作出口信息
typedef struct
{
    // 电流保护
    ProtState  i_sd;     // 电流速断保护
    ProtState  i_oc;     // 过流保护
    // 电压保护
    ProtState  u_ov;     // 过压保护
    ProtState  u_uv;     // 欠压保护
    // 阻抗保护
    ProtState  z_prot;   // 阻抗保护
    // 变压器差动保护
    ProtState  diff_prot;// 差动保护
    // 总出口状态
    uint8_t    total_out;// 总出口（TRIP_OUT/ALARM_OUT/0）
}ProtExport;
/************************ 基础算法函数 ************************/
// 1. 计算真有效值（采样值数组 → 有效值）
float calc_rms(float *buf, int len)
{
    float sum = 0.0f;
    for(int i = 0; i < len; i++)
    {
        sum += buf[i] * buf[i];  // 平方和
    }
    return sqrtf(sum / len);  // 有效值 = 根号(平方和/采样点数)
}
// 2. 二次谐波含量计算（简化FFT，工程实用算法，防止励磁涌流误动）
float calc_2nd_harmonic(float *sampleBuf, int len)
{
    float harm2 = 0.0f;
    for(int i = 0; i < len; i++)
    {
        // 二次谐波频率为100Hz，计算其幅值分量
        harm2 += fabsf(sampleBuf[i] * cosf(4 * PI * i / len));
    }
    return harm2 / len;  // 归一化二次谐波含量
}
// 3. 阻抗计算（U/I，相电压/相电流，计算阻抗值和阻抗角）
void calc_impedance(ThreePhase u_rms, ThreePhase i_rms, ImpedanceData *pZ)
{
    // 避免电流为0，防止除零错误
    float eps = 0.001f;
 // A相阻抗计算（Z=U/I，阻抗角=arctan(无功/有功)，简化为相位差近似）
    pZ->Z_A = (i_rms.A > eps) ? (u_rms.A / i_rms.A) : 0.0f;
    pZ->Z_angle_A = (i_rms.A > eps) ? (atan2f(u_rms.A, i_rms.A) * 180 / PI) : 0.0f;
    // B相阻抗计算
 pZ->Z_B = (i_rms.B > eps) ? (u_rms.B / i_rms.B) : 0.0f;
    pZ->Z_angle_B = (i_rms.B > eps) ? (atan2f(u_rms.B, i_rms.B) * 180 / PI) : 0.0f;
    // C相阻抗计算
    pZ->Z_C = (i_rms.C > eps) ? (u_rms.C / i_rms.C) : 0.0f;
    pZ->Z_angle_C = (i_rms.C > eps) ? (atan2f(u_rms.C, i_rms.C) * 180 / PI) : 0.0f;
}
/************************ 各保护模块逻辑 ************************/
// 1. 电流保护（速断 + 过流）
void current_protect(ThreePhase i_rms, ProtExport *export)
{
    // 电流速断保护：任一相电流超过整定值 → 立即跳闸（无延时）
    if(i_rms.A > I_SD_SET || i_rms.B > I_SD_SET || i_rms.C > I_SD_SET)
    {
        export->i_sd = PROT_TRIP;
    }
    else
    {
        export->i_sd = PROT_NORMAL;
    }
    // 过流保护：任一相电流超过整定值 → 延时跳闸（此处简化，实际需加定时器实现延时）
    if(i_rms.A > I_OC_SET || i_rms.B > I_OC_SET || i_rms.C > I_OC_SET)
    {
        export->i_oc = PROT_TRIP;
 }
    else
    {
        export->i_oc = PROT_NORMAL;
    }
}
// 2. 电压保护（过压 + 欠压）
void voltage_protect(ThreePhase u_rms, ProtExport *export)
{
    // 过压保护：任一相线电压超过整定值 → 延时跳闸
    if(u_rms.A > U_OV_SET || u_rms.B > U_OV_SET || u_rms.C > U_OV_SET)
    {
        export->u_ov = PROT_TRIP;
    }
    else
    {
        export->u_ov = PROT_NORMAL;
 }
    // 欠压保护：任一相线电压低于整定值 → 延时跳闸
    if(u_rms.A < U_UV_SET || u_rms.B < U_UV_SET || u_rms.C < U_UV_SET)
    {
        export->u_uv = PROT_TRIP;
    }
    else
    {
        export->u_uv = PROT_NORMAL;
    }
}
// 3. 阻抗保护（距离保护Ⅰ段，简化版）
void impedance_protect(ImpedanceData *pZ, ProtExport *export)
{
    // 任一相阻抗低于整定值，且阻抗角在保护范围内 → 跳闸
    if( (pZ->Z_A < Z_SET && fabsf(pZ->Z_angle_A) < 60.0f) ||
        (pZ->Z_B < Z_SET && fabsf(pZ->Z_angle_B) < 60.0f) ||
        (pZ->Z_C < Z_SET && fabsf(pZ->Z_angle_C) < 60.0f) )
    {
        export->z_prot = PROT_TRIP;
    }
    else
    {
        export->z_prot = PROT_NORMAL;
    }
}
// 4. 变压器差动保护（比率制动 + 二次谐波闭锁）
void trans_diff_protect(TransCurr transCurr, float *sampleA, float *sampleB, float *sampleC, DiffProtectData *pDiff, ProtExport *export)
{
    ThreePhase high = transCurr.highSide;
    ThreePhase low = transCurr.lowSide;
    // 1. 平衡系数折算 + 相位校正（高压侧电流折算到低压侧）
    float highA = high.A * BALANCE_K;
    float highB = high.B * BALANCE_K;
    float highC = high.C * BALANCE_K;
    // 2. 计算差流（差流 = |高压侧折算电流 - 低压侧电流|）
    pDiff->diff_A = fabsf(highA - low.A);
    pDiff->diff_B = fabsf(highB - low.B);
    pDiff->diff_C = fabsf(highC - low.C);
    // 3. 计算制动电流（制动电流 = (|高压侧折算电流| + |低压侧电流|) / 2）
    pDiff->restrain_A = (fabsf(highA) + fabsf(low.A)) / 2.0f;
    pDiff->restrain_B = (fabsf(highB) + fabsf(low.B)) / 2.0f;
    pDiff->restrain_C = (fabsf(highC) + fabsf(low.C)) / 2.0f;
    // 4. 计算二次谐波含量（输入A、B、C相采样数组）
    pDiff->harm2_A = calc_2nd_harmonic(sampleA, SAMPLE_POINT);
    pDiff->harm2_B = calc_2nd_harmonic(sampleB, SAMPLE_POINT);
    pDiff->harm2_C = calc_2nd_harmonic(sampleC, SAMPLE_POINT);
    // 5. 差动保护判据：比率制动 + 二次谐波闭锁
    int tripFlag = 0;
    float limitCurr;
    // A相判据
    limitCurr = DIFF_START + RATIO_SLOPE * pDiff->restrain_A;
    if(pDiff->diff_A > limitCurr && pDiff->harm2_A < HARM_THRESH)
        tripFlag = 1;
    // B相判据
    limitCurr = DIFF_START + RATIO_SLOPE * pDiff->restrain_B;
    if(pDiff->diff_B > limitCurr && pDiff->harm2_B < HARM_THRESH)
        tripFlag = 1;
    // C相判据
    limitCurr = DIFF_START + RATIO_SLOPE * pDiff->restrain_C;
    if(pDiff->diff_C > limitCurr && pDiff->harm2_C < HARM_THRESH)
        tripFlag = 1;
    // 设定差动保护状态
    export->diff_prot = tripFlag ? PROT_TRIP : PROT_NORMAL;
}
/************************ 自主编程扩展接口 ************************/
// 用户自定义保护逻辑（可自由添加自定义判据、扩展保护功能）
void user_self_logic(ThreePhase i_rms, ThreePhase u_rms, ImpedanceData *pZ, DiffProtectData *pDiff, ProtExport *export)
{
    // 示例1：自定义告警逻辑（差流未达到跳闸，但超过启动电流的50%）
    if( (pDiff->diff_A > DIFF_START * 0.5f || pDiff->diff_B > DIFF_START * 0.5f || pDiff->diff_C > DIFF_START * 0.5f) && export->diff_prot == PROT_NORMAL )
    {
        export->diff_prot = PROT_ALARM;
    }
    // 示例2：自定义阻抗保护告警（阻抗接近整定值，未达到跳闸）
    if( (pZ->Z_A < Z_SET * 1.2f && pZ->Z_A > Z_SET) && export->z_prot == PROT_NORMAL )
    {
        export->z_prot = PROT_ALARM;
    }
    // 可添加其他自定义逻辑：零序保护、过励磁保护、故障录波触发等
}
/************************ 装置级主保护逻辑 ************************/
// 综合保护主函数（整合所有保护模块，执行保护判断，输出动作结果）
void device_prot_main(TransCurr transCurr, ThreePhase u_rms, float *sampleA, float *sampleB, float *sampleC, DiffProtectData *pDiff, ImpedanceData *pZ, ProtExport *export)
{
    // 1. 初始化出口状态
    *export = (ProtExport){0};
    // 2. 计算三相电流有效值（高压侧、低压侧）
    ThreePhase i_rms_high = {
        .A = calc_rms(sampleA, SAMPLE_POINT),
        .B = calc_rms(sampleB, SAMPLE_POINT),
        .C = calc_rms(sampleC, SAMPLE_POINT)
    };
    // 此处简化：低压侧电流采样可单独传入，此处复用高压侧采样逻辑（实际需单独处理）
    ThreePhase i_rms_low = i_rms_high;
    transCurr.highSide = i_rms_high;
    transCurr.lowSide = i_rms_low;
    // 3. 执行各保护模块
    current_protect(i_rms_high, export);       // 电流保护
    voltage_protect(u_rms, export);            // 电压保护
    calc_impedance(u_rms, i_rms_high, pZ);     // 计算阻抗
    impedance_protect(pZ, export);             // 阻抗保护
    trans_diff_protect(transCurr, sampleA, sampleB, sampleC, pDiff, export); // 差动保护
    // 4. 执行用户自主编程逻辑
    user_self_logic(i_rms_high, u_rms, pZ, pDiff, export);
    // 5. 总出口判断：任一保护跳闸 → 总跳闸出口；任一保护告警 → 总告警出口
    if(export->i_sd == PROT_TRIP || export->i_oc == PROT_TRIP ||
       export->u_ov == PROT_TRIP || export->u_uv == PROT_TRIP ||
       export->z_prot == PROT_TRIP || export->diff_prot == PROT_TRIP)
    {
        export->total_out = TRIP_OUT;
    }
    else if(export->i_sd == PROT_ALARM || export->i_oc == PROT_ALARM ||
            export->u_ov == PROT_ALARM || export->u_uv == PROT_ALARM ||
            export->z_prot == PROT_ALARM || export->diff_prot == PROT_ALARM)
    {
        export->total_out = ALARM_OUT;
    }
    else
    {
        export->total_out = 0;
    }
}
/************************ 测试主函数（模拟装置运行） ************************/
int main(void)
{
    // 1. 模拟采样数据（A、B、C相采样数组，模拟故障状态）
    float sampleA[SAMPLE_POINT] = {0};
    float sampleB[SAMPLE_POINT] = {0};
    float sampleC[SAMPLE_POINT] = {0};
    for(int i = 0; i < SAMPLE_POINT; i++)
 {
        // 模拟A相故障电流采样（幅值6A，50Hz正弦波，叠加少量谐波）
        sampleA[i] = 6.0f * sinf(2 * PI * FREQ * i / SAMPLE_POINT) + 0.5f * sinf(4 * PI * FREQ * i / SAMPLE_POINT);
        // 模拟B、C相正常电流采样（幅值1A）
        sampleB[i] = 1.0f * sinf(2 * PI * FREQ * i / SAMPLE_POINT - 120 * PI / 180);
        sampleC[i] = 1.0f * sinf(2 * PI * FREQ * i / SAMPLE_POINT + 120 * PI / 180);
    }
    // 2. 模拟三相电压有效值（A相过压，B、C相正常）
    ThreePhase u_rms = {130.0f, 100.0f, 98.0f};
    // 3. 初始化变压器电流、差动数据、阻抗数据、保护出口
    TransCurr transCurr = {0};
    DiffProtectData diffData = {0};
    ImpedanceData impedanceData = {0};
    ProtExport protExport = {0};
    // 4. 执行装置级综合保护
    device_prot_main(transCurr, u_rms, sampleA, sampleB, sampleC, &diffData, &impedanceData, &protExport);
    // 5. 打印保护动作结果（模拟装置显示/上位机通信）
    printf("==================== 装置级综合保护动作结果 ====================\n");
    // 电流保护结果
    printf("电流速断保护：%s\n", protExport.i_sd == PROT_TRIP ? "跳闸" : (protExport.i_sd == PROT_ALARM ? "告警" : "正常"));
    printf("过流保护：%s\n", protExport.i_oc == PROT_TRIP ? "跳闸" : (protExport.i_oc == PROT_ALARM ? "告警" : "正常"));
    // 电压保护结果
    printf("过压保护：%s\n", protExport.u_ov == PROT_TRIP ? "跳闸" : (protExport.u_ov == PROT_ALARM ? "告警" : "正常"));
    printf("欠压保护：%s\n", protExport.u_uv == PROT_TRIP ? "跳闸" : (protExport.u_uv == PROT_ALARM ? "告警" : "正常"));
    // 阻抗保护结果
    printf("阻抗保护：%s（A相阻抗：%.2fΩ，阻抗角：%.1f°）\n",
           protExport.z_prot == PROT_TRIP ? "跳闸" : (protExport.z_prot == PROT_ALARM ? "告警" : "正常"),
           impedanceData.Z_A, impedanceData.Z_angle_A);
    // 差动保护结果
    printf("变压器差动保护：%s（A相差流：%.2fA，二次谐波含量：%.3f）\n",
           protExport.diff_prot == PROT_TRIP ? "跳闸" : (protExport.diff_prot == PROT_ALARM ? "告警" : "正常"),
           diffData.diff_A, diffData.harm2_A);
    // 总出口结果
    printf("总出口状态：%s\n", protExport.total_out == TRIP_OUT ? "跳闸出口" : (protExport.total_out == ALARM_OUT ? "告警出口" : "无出口"));
    printf("===============================================================\n");
    return 0;
}