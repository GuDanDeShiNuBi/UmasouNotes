### 技术分析

* unity官方不建议使用Resources来存储加载文件，会增加应用启动时间，除了assetbundle还有哪种方式
* 使用ini配置项文件存储数据库信息
* sql:select*from table where display=1
* [UI框架](https://blog.csdn.net/qq_34937637/article/details/80374387)
* [滑动列表](https://blog.csdn.net/linxinfa/article/details/122019054)
* [导入其他工程Assets问题](https://blog.csdn.net/linw321456/article/details/117785055)
* [unity生成的assets数据丢失](https://blog.csdn.net/u011926026/article/details/70156822?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1.no_search_link&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1.no_search_link&utm_relevant_index=1)
* 当循环查询数据库数据时，会造成查询慢，可以先把表查询，暂存在dataset中，再在dateset中查询
* 当循环更新数据时，可以将sql语句拼接为一个语句，仅进行一次更新



### 优化项
* 界面上方显示用户账户信息，用户类型  [管理员] [教师] [学生]
* 方案管理界面，创建者名字后显示哪个为自己的方案，或者创建者名字后显示用户类型

### 问题修改记录
- [x] 1、把方案输入框表头“计算基数（万元）/单价（元）”改成“计算基数（元）/单价（元）”
- [x] 2、基本预备费和价差预备费公式相乘基数改为0.02
- [x] 3、添加学生时，第一次选择无法选择添加一个学生:去除添加用户数量下拉框,数量限制为500
- [x] 4、管理员不需要新建方案,方案管理列表代码优化
- [x] 5、新建方案代码修改，新建方案弹窗界面关闭时应清除相关信息
- [x] 6、新建方案、删除方案、重命名方案界面优化 
- [x] 7、公式与界面中去除设备及安装工程某几个选项（光伏系统测控及通信屏、视频监控系统、防孤岛运行装置柜）
- [x] 8、数据输入输出格式均为保留小数点后三位
- [x] 9、方案费用合计导出表，格式及公式修改
- [x] 10、excel保存至电脑问题：excel处于打开状态是不可保存，同一名字excel会覆盖。目前改为调用windows系统保存界面，自定义文件名，如果存在该文件，提示是否替换。
- [x] 11、添加导出全部教师与学生账户功能
- [ ] 12、excel导入功能添加，创建方案模板excel,导入软件后自动填充
- [x] 13、导出的费用合计，“升压变电设备及安装工程”的各项费用计算有误
- [x] 14、密码加密方式修改，des加密（原来md5）


### 新发现问题
- [ ] 1、基于不同教师方案名可重复，数据库jzgcgsb_sol、qtfygsb_sol、number_sol中solname键建议改为solid，方便区别


### 工作记录
- [ ] 1、概算经评软著申请（登记测试申请材料）
- [ ] 2、仿真软件，漫游功能，如何漫游；定点展示信息，信息内容
