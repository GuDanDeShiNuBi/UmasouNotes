*   读取csv文件
    *   StreamReader.ReadLine逐行读取
        *   代码
              ```  private void ReadCsv()
               {
               StreamReader strReader = new StreamReader
               ("C:\\\\Users\\\\WS\\\\Desktop\\\\文档\\\\mycsvtest.csv");
               bool endOfFile = false;
               while (!endOfFile)
               {
               string data\_String = strReader.ReadLine();
               if ( data\_String== null){
               endOfFile = true;
               break;
               }
               var data\_value = data\_String.Split(',');
               //for (int i = 0; i < data\_value.Length; i++)
               //{
               // Debug.Log("Value:" + i.ToString() + " " + data\_value\[i\].ToString());
               //}
               Debug.Log(data\_value\[0\].ToString() + " " + data\_value\[1\].ToString() + " " + data\_value\[2\].ToString() + " ");
               }
               } 
    
*   untiy读写Excel
    *   [Unity读写Excel表格](https://juejin.cn/post/6991464138782277645#heading-5)
    *   [2](https://blog.csdn.net/wangjiangrong/article/details/79980447)
    *   [3](https://blog.csdn.net/yupu56/article/details/50580277)
        
*   FileStream
    *   [FileStream | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.filestream?view=net-6.0)
*   文件读写与路径
    *   [unity文件操作](https://www.jianshu.com/p/e46ea0ac1480)
*   unity读取json
    * [本地数据保存与读取]https://blog.csdn.net/czhenya/article/details/78057062
    * [三种保存方式]https://zhuanlan.zhihu.com/p/260157229
    * https://blog.csdn.net/yu1368072332/article/details/81138281

* 配置表读取插件：luban
  * https://gitee.com/focus-creative-games/luban