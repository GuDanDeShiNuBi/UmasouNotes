

20230529

1、软件归档
- 新型电力系统仿真规划设计软件（原2D高职）
  - 软件文档整理修改
- 新型电力系统能源场站仿真运维软件（原光伏电站虚拟仿真实训系统）

2、新型电力系统能源场站仿真运维软件账号创建
- 账号创建需在数据库手动创建，过于繁琐
- 增加软件创建账号功能（建议）
  - 添加教师账号界面功能
  - 删除教师账号界面功能
  - 批量添加学生账号界面功能
  - 批量导出学生账号界面与功能
- 增加账号密码错误提示
- 增加教师评分页软件关闭按钮

  20230602
  1、软件修改完有一个验收记录，不仅仅是口头的，书面的，避免遗忘，需求变更
  2、软件验收后，实际业务人员需实际运行几遍，不能自己一点不了解直接带到客户方测试
  3、业务部门自身没有进行对接，认知不统一

  20230613
  新型电力系统仿真规划软件，教师账号缺少‘添加学生账号’问题修改
  软件是否需要在归档审批里再次上传，是否上传竞赛版（去绑定）

  能源场站运维软件，自由巡检中，物体点击不到问题解决，测试（修改了模型，有模型遮挡）

  20230621 ##########################################################################################

  - [x] 能源场站软件问题：教学模式-巡检模块-组串式巡检中显示的故障位置不对，行列不对

  - [ ] 从光伏电站虚拟仿真实训系统（万维）、并网接入（1+x光伏）、设备仿真三个软件中整理模型资源，创建模型库，将模型分类保存

  - [ ] 分布式光伏电站项目继续跟进、学习光伏相关流程、基础知识


20230625

- [x] 能源场站软件问题巡检模块故障位置不对，行列不对
  - 教学模式中，巡检中故障位置与考试模式中故障位置相同，为防止直接抄袭此数据，因此教师模式中设定的巡检中故障位置并不正确，仅是参考作用

20230627
- [x] 新型电力系统仿真规划软件
  - 改分、建账号
  - 软件代码熟悉，框架研究

20230630
- [x] 苏州高等职业技术学校出现全部或多个流程结束后提交成绩，成绩未更新的情况
- 单独模块提交没有问题

2023.7.3
- [x] 能源场站软件修改（针对学校提交成绩后，成绩未更新问题）。
  - 版本号：V1.0.2
  - 修改了考试模式下的excel表，各流程步骤得分进行实时读取保存，最后提交成绩时进行上传

2023.710
- [x] 氢能、概算、经评软件，修改两版陪标软件
- 氢能
  - 修改首页、数据报表页，界面布局，文字大小、背景颜色
  - 社会效益去除两项
  - 功能描述换种说法
- 概算、经评软件
  - 修改排列顺序
  - 去除标题
  - 背景颜色修改

20230725
- [x] 考试模式中，热成像仪 成像不显示问题修改
  - 发布V1.0.3版本
  - 修改了考试模式excel，将热力图路径改为：Canvas.教学模式菜单.各种表.组件热力图。并将成像的UI复制到canvas.教学模式.各种表中，本来处于canvas.教学模式.案例21菜单中，属于bug
- [x] 新型电力系统仿真规划设计软件，方案运行折线图中，每日蓄能均大于0，但在成绩中供电天数不足为341天
  - 解决：方案中未设置气候参数 
- [x] 能源场站、答题系统软件的分数保存指导书编写

2023.0731
- [x] 教学模式中，点击光伏安全教程无反应
  - 发布V1.0.4版本
  - 原程序采用Resource 加载，编辑器模式可正常打开打包后出现问题。现修改为StreamingAssets加载

20230802
- [x] 在万维光伏运维源工程上，新创建一个版本，增加账号密码登录。增加账号创建工具。该软件数据库放在118.31.74.33:3306服务器
- [x] 新型电力系统运维软件，新版本软件提供给售后
- [x] 并网接入软件软件模型提取，问题修改m  

20230803
- [x] V1.0.3版本软件出现了切换到小窗口时，软件左上角窗口名称出现“改分工具”字样，为unity引擎打包发布配置问题
    - 仅V1.0.3版本存在这种状况，该版本目前未发送到学校使用，且软件为全屏使用
- [x] 组串式巡检考试热成像仪程序也不显示  

20230807
- [x] 成都电子成绩提交失败问题，测试。全部考核做完出现有时提交成绩失败的情况
- [x] 竞赛答题软件测试
    - 导出答题信息时，第100题答案未导出，问题查找修改
20230901
- [x] 2D仿真规划软件增加竞赛版，数据放在竞赛版数据库
- [ ] 仿真规划软件的服务器迁移,暂时不用
- [x] 国赛的教师及学生账号密码改为ry147258

20231020
- [x] 能源场站软件需整合出V1.0.5版本，将需要优化的点优化：1、滑动列表问题。2、考试模式倒数第二考核，有时50分，有时100分问题
- [x] 能源场站软件账号创建工具开发

20231024
- 3D仿真规划软件，数据库气候数据更新，年份从2013-2016更新为2019-2022，已测试，且旧的气候数据已在数据库备份（datatable 20231023beifen）

20231208
- 概算经评软件，退出账号不成功问题
- 光伏运维软件，成绩提交失败问题
- 光伏电站软件，原型确定，资料确定

20240102
- [ ] 概算经评软件卡死问题，账号无法正常退出
- [x] 光伏运维软件成绩上传失败，但本地有保存，数据库无任何记录
  - 将隐藏文件修改为加密或者权限文件
- [x] 概算经评保存流程指导书编写。
- [ ] 光伏电站设计与施工软件开发计划编写

20230103
- [x] 2d仿真规划软件出现自动修改为能源互联网仿真规划软件问题
  - 可能是自动更新问题导致，将相关程序注释

20240906
- [x] 光伏电站运维实训系统（1+x）发布linux,测试通过
- [ ] 分布式光伏仿真规划等这种一个教师端带很多学生端的，都改成3个点，比赛的版本不改
  - [ ] 先在分布式光伏仿真规划软件（2D）上改，尽量简单


20250221
- 0221福州机电试用账号一个月后删除（新型电力两个软件）
- 0225德化职校试用账号一个月后删除（新型电力两个软件）