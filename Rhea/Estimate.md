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