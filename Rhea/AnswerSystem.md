
##### 参考资料

读取与写入word

  aspose
  - [Aspose]https://blog.csdn.net/xunideshijie/article/details/120260722
  - [Aspose]https://blog.csdn.net/xunideshijie/article/details/122928314
  - [Aspose表格中插入行]https://blog.csdn.net/qq_39312554/article/details/107838161
  - [Aspose新建表格] https://blog.csdn.net/lordwish/article/details/104485557
  - [Aspose表格固定列宽]https://blog.csdn.net/zhangxc0310/article/details/89511309
    -  table.AutoFit(Aspose.Words.Tables.AutoFitBehavior.FixedColumnWidths);
 -  [多个doc合并]https://www.cnblogs.com/sxhlf/p/6709961.html
 -  [换页]https://blog.csdn.net/qq_38974638/article/details/107898625
  
  json
  - [本地数据保存与读取]https://blog.csdn.net/czhenya/article/details/78057062
  - [三种保存方式]https://zhuanlan.zhihu.com/p/260157229

NPOI
  - [NPOI]https://blog.csdn.net/weixin_38484443/article/details/102486057
  
读取写入txt
-[Txt文档操作]https://blog.csdn.net/q764424567/article/details/119612017
-[inputfield自适应]https://blog.csdn.net/qq_42437783/article/details/124776515
 https://www.jianshu.com/p/afcbefb44cce
 https://blog.csdn.net/qq_40120946/article/details/103559250?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-103559250-blog-124776515.pc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-103559250-blog-124776515.pc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=14
-[Text文字过长显示省略号]https://blog.csdn.net/zzxiang1985/article/details/82225615?spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-82225615-blog-114635039.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-6-82225615-blog-114635039.pc_relevant_aa&utm_relevant_index=9
- advancedInputfield

##### 软件

1、答题
- 登录页 ：工位号（输入框）、授权码（输入框）、登录（按钮）
- 考生须知页：操作使用说明（文字）
- 答题页：选择题（按钮）、填空题（按钮）、计算题（按钮）。答题页是否设计为一整页，可滚动样式
2、教师登录
- 导出所有学生答题信息，绘制成图片

3、替换信息应用
- 数据中台


##### 设计流程

- 工位号、授权码登录
- 选择题
  - 60题
  - 点击按钮选中
  - 是否可多选
- 填空题
  - 40题
  - 每题几个空，也可用括号或者逗号区分开
- 计算题
  - 10题
  - 直接输入
  - 计算符号键盘输入时有限制。增加特殊符号键盘，有操作难度
- 填写完成，点击提交，数据保存至数据库
  - 是否需要选择题、填空题、计算题各有一个提交按钮
  - 提交后是否增加哪些题未做的提示

- 教师导出答案
  - 点击导出，提取数据库学生答题信息，填入答题卡图片，保存至桌面
  - 导出tex,保存
  - 导出word保存

20230203 设计修改
- 答题统一为简答题题型
- 每题填写内容，超过一行时，进行自适应，往下延伸一行
- 数据库权限划分，非项目人员不可访问
- 管理员、教师权限、学生权限。
- 账号管理（新建、删除）

20230211 设计修改
- 批量生成账号、修改删除账号、批量导出账号功能开发
- 增加主界面：管理、导出
- 答题信息保存、答题信息读取与处理，并批量导出等功能开发
- 批量导出账号，改为导出word文档，一个账号一个文档
- 学生账号不存在新建方案步骤，新建账号时新建方案，答题界面提交后更新方案
- 设置为100道题
- 将答题信息保存到数据库
- 进入答题界面读取上次答题信息，自动写入
- 导出word表格，表格随内容自适应，最终转为图片形式保存到本地
- 答题过程中进行数据备份缓存
- 管理员工具：快捷复制替换答题信息

20230221
- [x] 批量导出账号在一个word文档内，每个账号占一页(可批量打印)
- [x] 返回按钮位置调整
- [x] 导出答题信息界面，描述修改“如无需全部导出，请选择题目数量”
- [x] 没有进入过考试系统的账号，考试信息也需导出
- [x] 账号管理界面显示密码
- [x] 应用程序包大小还可优化，删除字体
- [x] 功能完善：编辑学生username的同时修改answer库对应的username。删除某个用户的同时删除其方案
- [x] 完善答题信息本地存储加载功能，按照用户名保存到streamingassets文件夹，以用户名命名文件，加载时判断文件是否存在，存在即本地加载，不存在则数据库加载
- [x] 添加管理员替换学生答题信息界面及功能(多方案创建，一键替换)

20230321
- [x] 给教师账号添加赛项名称输入框，教师可自定义设置学生账号word文档的标题内容

数据库设计
- 用户表：ID,账号、密码、用户类型（权限）、teacherid
  - 教师使用账号、密码登录
  - 教师指的是2023中职比赛
- 答题表：id,userid,teacherid,每题的答案

20230713
- [x] 管理员改分工具增加一层赛项（教师）选择，让管理员基于某个赛项进行分数修改
  - 管理员在创建的方案时，数据库所属教师为其选择的教师
  - 方案列表筛选条件为：选择username=admin,teaname=下拉框选择的教师 的方案
  - 数据库teaid为教师端导出学生答题信息时使用，teaname用于管理员创建方案区分教师的时候
- [x] 改分工具中 增加已修改人员记录，即工位号记录
- [x] 考试须知精简，只留1，2两项
- [x] 答题界面增加提交后退出按钮
- [x] 答题信息导出表修改，第一行为赛项名称，第二行为工位号，居中
- [x] 账号导出表，内容居中,按照模板进行修改
- [x] 软件界面更改
- [x] 答题界面点击帮助后，答题内容丢失问题修改
  - studentNotice脚本中：UIPanelManager.Instance.PushPanel(UIPanelType.Answer);导致调用了answer界面的onEnter(),对界面进行了刷新，数据重新进行了读取（本地加载的）
  - 采用了：考试须知界面放到了答题页
  - 也可采用：在answer脚本，界面退出时进行本地数据缓存，Onpause()
- [x] 教师端主页面增加赛项名称，为标题
  - 教师管理界面设置完赛项名后，随后更新为主页标题
  - 在批量导出时进行赛项名称保存，保存至数据库user表，登录时读取，显示在主页和账户管理页
- [x] 答题界面增加题号，答案标题列
- [x] 管理员界面修改
- [x] 界面自适应
- answer代码里去除了本地读取，直接数据库读取，本地缓存读取，在更换电脑是会有问题
- [x] 改分工具中增加学生答题信息预览功能

20240123
- 软件修改，改为自动评分模式
  - 评分区分选择题、填空题。教师在建账号时，提供答案，填空题提供关键字

20240221
- 修改问题：1、选择题的题目位置和数量不确定。2、选择题的填写形式是选择还是填空 。3、选择题和填空题是否分开展示。  4、教师建账号时提供答案的界面
- [x] 选择题和填空题在一页，问答题单独一页
- [x] 教师界面提供一个输入答案的入口（在教师主界面增加一个编辑按钮，点击进入答题界面）
- [x] 评分界面：在教师主界面增加一个评分按钮，点击进入显示所有考生账号及成绩，点击进入可查看考生作答信息
- 选择题填空题分值，简答题每个关键词对应分值，每题分值
- [x] 给每题设置可填写的分值，在教师输入答案处，存储在数据库
- [x] 选择填空题，不区分大小写，自动去除空格
- [x] 简单题关键词对比，学生简答题是否存在关键词
- [x] 简答题分值为总分值，简答题每空得分=分值/关键词数量
- [x] 选择题200道，简答题100道
- [x] 分数导出功能，导出为excel表
- [x] 导出表修改，增加简答题导出
- [x] 可设置选择简答的导出题目数量
- [x] 学生答案查看功能添加
- [x] 改分工具修改（复制、粘贴、查询、管理员答题界面、新建方案、学生答题界面）
- [x] 部分代码完善（多次成绩汇总会叠加信息）
- [x] 去除简答题的大小写敏感，空格
- [x] 去除学生选择填空题的标点符号（，、。）
- [x] 教师填写简答题答案是用逗号隔开（中英文逗号均可）
- [x] 分数设置为可输入小数点
- [x] 分数保留小数点后三位
- [x] 增加导出表，可导出学生成绩具体信息表，显示对错，每题得分\分值                 
- [x] 总成绩表以excel表的形式，其他以pdf显示
- [x] 题目名称改为答题卡1，答题卡2
- [x] 题序：答题卡1从1.1排列到1.200  答题卡2从2.1到2.100

- 20240321测试修改
  - 是否应该去除选择题的标点符号，现在为不去除
  - 去除选择题中的换行、回车
  - 去除简答题中的换行、回车
  - 去除简答题中 括号的 中英文敏感
  - 使用replace(" ","")仅去除了字符串中间的空格，使用trim去除开头和结尾的空格

