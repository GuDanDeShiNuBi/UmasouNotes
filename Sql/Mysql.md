*   可视化工具
    *   Navicat
        *   Navicat15激活
            *   [Navicat Premium 15 ](https://www.cnblogs.com/no-celery/p/14824579.html)
*   安装
    *   [Mysql安装教程](https://zhuanlan.zhihu.com/p/188416607)
    *   安装后设置环境变量，方便cmd操作
*   mysql&unity
    *   [简单连接](https://zhuanlan.zhihu.com/p/28401873)
    *   [unity数据增删改查](https://blog.csdn.net/qq_14942529/article/details/103891634)
    *   [mysqlcommond&mysqldataAdapter区别](https://blog.csdn.net/qq_39657909/article/details/80615355)
    *   MySqlDataAdapter
        *   SqlDataAdapter内部通过SqlDataReader获取数据，而默认情况下SqlDataReader不能获知其查询语句对应的数据库表名,所以当mysqldataAdapter.fill(dataset)时，会在DataSet中创建一个新的DataTable，这个新的DataTable会拥有名为CustomerID和CompanyName 列，但是DataTable对象的名称是Table，而不是我们希望的Customers。
        *   [mysqldataadapter](https://blog.csdn.net/gatieme/article/details/20695853)
    *   [交互](https://blog.csdn.net/wks310/article/details/86543891)
    *   DataTable
    *   DataSet
    *   [方法封装](https://www.programminghunter.com/article/362126543/)
*   连接打包
    * unity想要与mysql连接，需要导入mysql.data.dll文件
    * 导入dll文件会遇到版本问题，需要确认unity对应的.Net版本及Api compatibility level(.Net4x),然后确认mysql对应版本，MySql驱动包需要与Unity版本对应，比如我用的Unity2017.1.1，只能支持.net 3.5及以下的版本，所以下载的时候，请让MySql.Data.dll支持的版本小于或等于你的Unity支持的版本
    * mysql.data.dll下载，mysql官网，MySQL for Visual Studio下载
    * 导入I18N.dll/I18N.CJK.dll/I18N.West.dll，system.data.dll,system.drawing.data.dll
    * bug
      * 1、Assembly ‘Assets/Plugins/MySql.Data.dll’ will not be loaded due to errors:  版本过高
      * 2、Client does not support authentication protocol requested by server; consider upgrading MySQL client:  版本太低
      * 3、- 导入I18N.dll/I18N.CJK.dll/I18N.West.dll\system.data.dll,system.drawing.data.dll时报错：  选择E:\Unity\Editor\Data\MonoBleedingEdge\lib\mono\unityjit中的导入,dll文件对应.Net版本需要跟unity.Net版本一致  
      * 打包后报错（The type initializer for 'MySql.Data.MySqlClient.Replication.ReplicationManager' threw an exception.）：1、添加I18n\I18N.cjk\I18N.west
        2、将projecsetting/player/othersetting/Configuration中的Api Compatibility Level 改为.NET 4.x
*   语法
    *   [SQL是什么？它能做什么？](http://c.biancheng.net/view/7566.html)
    *   [SQL INSERT INTO 语句 ](https://www.runoob.com/sql/sql-insert.html)
    *   sql运算符
    *   sql Where子句
    *   [sql 预处理语句：Mysql将prepare、excute、deallcate统称为PREPARE STATEMENT，即预处理语句](https://www.cnblogs.com/geaozhang/p/9891338.html)
        *   PREPARE语句用于预备一个语句，并指定名称statement_name，以后引用该语句。语句名称对大小写不敏感。preparable_stmt可以是一个文字字符串，也可以是一个包含了语句文本的用户变量。该文本必须表现为一个单一的SQL语句，而不是多个语句。在这语句里，‘?’字符可以被用于标识参数，当执行时，以指示数据值绑定到查询后。‘?’字符不应加引号，即使你想要把它们与字符串值结合在一起。参数标记只能用于数据值应该出现的地方，而不是SQL关键字，标识符，等等。如果预语句已经存在，则在新的预语句被定义前，它会被隐含地删掉
    *   pk-主键  fk-外键
*   命令行操作
    *   打开数据库
        *   \-u root -p
    *   选择数据库
        *   use dabsname
*   数据库设计
    *   实体关系图（ERD）
