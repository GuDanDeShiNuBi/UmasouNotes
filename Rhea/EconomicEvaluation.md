### 经评开发记录

- [x] 将管理员用户管理与教师用户管理界面进行统一，合并为一个，去除了manageruser_tea
- [x] 导出学生账号与教师账号
- [x] 设计并搭建方案编辑界面（基础数据）
- [x] 编辑基础数据界面：数据输入、保存、自动计算、更新
- [x] 搭建发电量变界面，编辑发电量表的数据,保存数据，更新数据
- [x] 保存当前数据时，根据计算公式，更新并保存其他表受影响的数据

- [x] 确认各数据单位，计算前需进行数据转换（百分号，万元，元）
- [x] decimal.parse改为：1、decimal.tryparse 2、convert.todecimal（数据库源数据，rows[][]）否则数据过大时会报错或数据异常
- [x] 将各表计算数据分离到一个单独的类中
- [x] 部分合计数据未计算
- [x] 数据计算后，需保存两次才能正确保存，部分表数据需等待其他表计算完成后才能正确计算
- [x] 概算最终计算数值，进入经评后应换算为万元
- [x] 计算数值小数点后有效位限制
- [ ] 数据库sol表数据,部分可为空，部分不能为空，导致界面未输入数据部分为空，部分为0
- [x] 删除方案功能完善
- [x] 删除用户功能完善
- [x] 初次创建方案，进入方案编辑界面后报空，UpdateInputFiled_BD
- [ ] 评分规则设定：1、首先对比基础数据中的必填项（即参数正确性），其中规划装机容量改为范围值。2、对比基础数据中概算数据是否与概算软件一致；3、评分表各项数据分值为12.5分，共8项。除每瓦投资额外，各项数据并按从大到小的顺序降序排列，每瓦投资额按照从小到大的顺序排列，第一名得为12.5分，按照顺序得分依次减少，扣分值为0.5分，最低分为5分
- [x] 教师管理用户界面，导出学生账号后，界面无法触发事件。(判断桌面进程是否结束，即filemanager是否返回为null)
- [x] 方案进行导出保存文件后，如何桌面进程点击关闭或者取消保存，返回应用会无法触发界面
- [ ] irr计算公式还需测试，部分数据不符合计算要求，目前返回为0


### 发现问题

- [ ] 目前账号不能同时登录概算和经评两个软件，设置是一个账号同一时间只能登录一台设备
- [x] 基础数据的数据单位不统一，不完整
- [ ] 25年总发电=【表2 发电量表】实际发电电量（合计）=光伏发电量+风力发电量
- [x] 借款偿还期（合计）=【基础数据】BOS价格，目前方案数据不含BOS价格,bos=合计
- [ ] 删除教师账户时，该教师账户下学生账户是否删除，学生的方案是否删除
   

### 相关资料

- [npv计算](https://support.microsoft.com/zh-cn/office/npv-%E5%87%BD%E6%95%B0-8672cb67-2576-4d07-b67b-ac28acf2a568)
- [pmt](https://support.microsoft.com/zh-cn/office/pmt-%E5%87%BD%E6%95%B0-0214da64-9a63-4996-bc20-214433fa6441)
  - public static double PMT(decimal yearlyInterestRate, decimal totalNumberOfMonths, decimal loanAmount)
    {
        var rate = (double)yearlyInterestRate / 100 ;
        var denominator = Math.Pow((1 +  rate),(double) totalNumberOfMonths) - 1;
        return (rate + (rate / denominator)) *(double) loanAmount;
    }
- IRR 内部收益率计算
  - https://www.codeproject.com/Tips/461049/Internal-Rate-of-Return-IRR-Calculation
  - https://github.com/srbrettle/Financial-Formulas-Library-.NET-Standard
  - https://support.microsoft.com/zh-cn/office/irr-%E5%87%BD%E6%95%B0-64925eaa-9988-495b-b290-3ad0c163c1bc?msclkid=46ac8e95cfff11ec8accbc0b2d8186b7
  - https://zhuanlan.zhihu.com/p/425433706?msclkid=ce21edc6d00511ec9a816d2cee8e08ce
  - https://zhuanlan.zhihu.com/p/350931499?msclkid=4c635bf0d00b11ecba48b659caf452b2
  - https://blog.csdn.net/qianyun6/article/details/23022441?msclkid=8e97c338d00f11ec9dc10e9aab11c38d
  - https://blog.csdn.net/weixin_41276332/article/details/78725340?msclkid=6c4f2ef0d02711eca25016c15d70ad02
- [Financial](https://github.com/Hesapkurdu/hk-financial-functions)