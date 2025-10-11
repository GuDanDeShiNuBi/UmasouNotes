*   读取csv文件
    *   StreamReader.ReadLine逐行读取
        *   代码
              ```  private void ReadCsv()
               {
               StreamReader strReader = new StreamReader
               ("C:\\\\Users\\\\WS\\\\Desktop\\\\文档\\\\mycsvtest.csv");。
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
    * JsonUtility.FromJson<T>() 是 Unity 内置的 JSON 反序列化方法，用于将 JSON 字符串转换为 C# 对象（反序列化）。它是 Unity 自带的 UnityEngine 命名空间下的工具，无需额外导入 DLL，适合在 Unity 项目中处理 JSON 数据。
      * 1. 类必须标记 [Serializable]
           被序列化的自定义类 / 结构体必须添加 [System.Serializable] 特性（注意是 System 命名空间下的），否则无法被 JsonUtility 识别。
      * 2. 字段必须可访问
            必须是 public 字段（推荐）；
            若为 private 字段，需添加 [SerializeField] 特性强制序列化。
      * 3. JSON 结构必须与类结构匹配
            JSON 的键名必须与 C# 类的字段名 完全一致（包括大小写）；
            JSON 必须有一个 根对象（不能直接解析顶级数组，需用类包裹）。
      * 完整代码(读取json文件)： 
              ``` C#
                     using System;
                                  using System.Collections.Generic;
              
                                  [Serializable]
                                  public class Book {
                                      public string bookName; // 对应 JSON 中的 "bookName"
                                      public string author;   // 对应 JSON 中的 "author"
                                      public int publishYear; // 对应 JSON 中的 "publishYear"
                                  }
              
                                  [Serializable]
                                  public class BookList {
                                      public List<Book> books; // 对应 JSON 中的 "books" 数组
                                  }
              
              
                                  {
                                      "books": [
                                          {
                                              "bookName": "百年孤独",
                                              "author": "加西亚·马尔克斯",
                                              "publishYear": 1967
                                          },
                                          {
                                              "bookName": "三体",
                                              "author": "刘慈欣",
                                              "publishYear": 2008
                                          }
                                      ]
                                  }
              
                                  using UnityEngine;
              
                                  public class JsonExample : MonoBehaviour {
                                      public TextAsset jsonFile; // 拖拽 JSON 文件到 Inspector
              
                                      void Start() {
                                          if (jsonFile == null) {
                                              Debug.LogError("请赋值 JSON 文件！");
                                              return;
                                          }
              
                                          // 解析 JSON 字符串为 BookList 对象
                                          BookList bookList = JsonUtility.FromJson<BookList>(jsonFile.text);
              
                                          // 验证解析结果
                                          if (bookList != null && bookList.books != null) {
                                              foreach (var book in bookList.books) {
                                                  Debug.Log($"书名：{book.bookName}，作者：{book.author}，年份：{book.publishYear}");
                                              }
                                          } else {
                                              Debug.LogError("解析失败！");
                                          }
                                      }
                                  }
              ```     
      * Unity 的JsonUtility有一个限制：不能直接序列化 / 反序列化数组作为根元素，必须将数组放在一个类（或结构体）中作为根对象的字段。所以生成写入json文件时，不能以Book直接序列化文件，这样的话，生成的json文件缺少根结构{ "books": [ ... ] },要以BookList为根对象对类进行序列化， 它具有一个字段public List<Book> books，添加数据往books中添加，当数组有多个元素时,json文件序列化后为："books": [ { ... }, { ... } ]
* 配置表读取插件：luban
  * https://gitee.com/focus-creative-games/luban