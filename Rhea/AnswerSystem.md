
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