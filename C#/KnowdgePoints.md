*   C#
    *   字符串
        *   split
            *   字符串分割
                *   exp:字符串分割去空
                    *   private static readonly string\[\] PathSplitSeparator = new string\[\] { ".", "/", "\\\\" };
                    *   path.Split(PathSplitSeparator, StringSplitOptions.RemoveEmptyEntries)
        *   String.trim()
            *   若想把一个字符串首尾处的一些特殊字符剪切掉，如去掉一个字符串首尾的空格等，可以使用String的Trim()方法。其形式如下：
            *   同Trim类似，TrimStart和TrimEnd分别剪切掉一个字符串开头和结尾处的特殊字符。
        *   字符串拼接
            *   “+=” 拼接法
                *   string str="a";str+="b"+"c"
                *   首先需要明白的是string类型，string是引用类型，保留在堆上，而不是栈上，用的时候传的是内存中的地址，每次修改就会重新创建一个新的string对象来存储字符串，原有的会被自动回收。
                *   　　第一种方式的实现原理，第一步先在内存中分配空间，存储str变量的对象，值为"a", “+=”时，又会重新创建一个对象来存储新的字符串（“abc"）,把str指向这个新的地址。所以只有简单几步的拼写时，一般不会有太大问题，如果有时候需要循环拼接时，就会不断创建新的对象，很浪费性能和内存。
            *   String.Format()
                *   源码：
                    *   public static String Format(IFormatProvider provider, String format, params Object\[\] args) <br>{
                    *   if (format == null || args == null)
                    *   throw new ArgumentNullException((format==null)?"format":"args");
                    *   　　　　StringBuilder sb = new StringBuilder(format.Length + args.Length \* 8);
                    *   　　　　sb.AppendFormat(provider,format,args);
                    *   return sb.ToString();
                *   可以看到是先创建一个StringBuilder类型的变量，长度为第一个参数的长度+参数长度的8倍。.Net自动分配一个比较大的容量来存储。这种方式的代码看起来比较整洁，易于阅读，效率也比“+=”高效很多
            *   StringBuilder.Append
                *   示例
                    *   StringBuilder str=new StringBuilder();
                    *   str.Append("a")
                *   StringBuilder 是预先创建一个比较大的内存，以后每次操作时判断容量上限是否不够用，如果不够用就自动把容量扩大一倍，修改的还是第一次创建的对象的值。
            *   小结
                *   如果是简单的拼写时，可以用 "+=", string.format
                *   大量或者循环内拼接很长的字符串时，就需要用到StringBuilder来节省性能和内存了。
        *   字符串删除指定字符
            *   String.Replace("#","")
        *   字符串截取
            *   [String.Substring 方法 (System) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.substring?view=net-5.0)
        *   string.indexof()
            *   查找索引
                *   [String.IndexOf 方法 (System) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.string.indexof?view=net-5.0)
    *   结构体
        *   值类型（Vector2,Vector3）
        *   可继承于接口
    *   readonly与const
        *   const是静态常量或者叫编译时常量，是指编译器在编译时候会对常量进行解析，并将常量的值替换成初始化的那个值。必须在声明的时候初使化， const 关键字声明的字段默认带有 static 属性，因此只可以通过类对 const 常量进行访问
        *   readonly称为动态常量，也叫运行时常量，运行时常量的值是在运行的那一刻才获得的，编译器编译期间将其标示为只读常量，而不用常量的值代替，这样动态常量不必在声明的时候就初始化（当然也可以在声明的时候初使化），而可以延迟到构造函数中初始化。
        *   [C# 静态常量与动态常量\_Wcl-joker的博客-CSDN博客\_c# 静态常量](https://blog.csdn.net/qq_39059405/article/details/86000449)
    *   sealed关键字
        *   作用在类或方法上表示不可以被继承或重写
            *   public sealed class Object{}
            *   public sealed override void Move(){}
    *   partial关键字
        *   可以把某个类的实现写为几个部分，分布到不同的文件中，避免一个类文件过长。 如：实现MVC时，分文件写比较清晰。
        *   exp:
            *   public partial class DLCManager : GameSingleton{}
    *   类的继承
        *   一个类，可以继承自一个普通类，继承它的成员变量和方法；也可同时继承自 一个接口，继承接口的方法并完成定义
    *   using System.Runtime.InteropServices
        *   提供各种支持 COM 互操作和平台调用服务的成员
        *   [System.Runtime.InteropServices 命名空间 | Microsoft Docs](https://docs.microsoft.com/zh-CN/dotnet/api/system.runtime.interopservices?view=net-5.0)
    *   泛型类型限定
        *   public class CacheHelper<T> where T:new(){}
            *   泛型限定条件：
            *   T：结构（类型参数必须是值类型。可以指定除 Nullable 以外的任何值类型）
            *   T：类 （类型参数必须是引用类型，包括任何类、接口、委托或数组类型）
            *   T：new() （类型参数必须具有无参数的公共构造函数。当与其他约束一起使用时new() 约束必须最后指定）
            *   T：<基类名> 类型参数必须是指定的基类或派生自指定的基类
            *   T：<接口名称> 类型参数必须是指定的接口或实现指定的接口。可以指定多个接口约束。约束接口也可以是泛型的。
            *   T：U
    *   条件表达式
        *   ？：
            *   条件？X:Y
                *   如果条件为真 ? 则为 X : 否则为 Y
    *   可空类型修饰符
        *   ？
            *   引用类型可以使用空引用表示一个不存在的值，而值类型通常不能表示为空。
            *   例如：string str=null; 是正确的，int i=null; 编译器就会报错。
            *   为了使值类型也可为空，就可以使用可空类型，即用可空类型修饰符 ? 来表示，表现形式为 T? 。
            *   例如：int? 表示可空的整形，DateTime? 表示可为空的时间。
            *   T? 其实是 System.Nullable(泛型结构）的缩写形式，也就意味着当你用到 T？时编译器编译时会把T？编译成 System.Nullable 的形式。
            *   例如：int?，编译后便是 System.Nullable 的形式。
        *   ?:
            *   三元运算符表达式
                *   例如：x?y:z 表示如果表达式 x 为 true，则返回 y；如果 x 为 false，则返回 z，是 if{}else{} 的简单形式。
        *   ？？
            *   空合并运算符
                *   用于定义可空类型和引用类型的默认值。
                *   如果此运算符的左操作数不为 null，则此运算符将返回左操作数，否则返回右操作数。
                *   例如：a??b 当 a 为 null 时则返回 b，a 不为 null 时则返回 a 本身。
    *   空值传播运算符
        *   ?.
            *   *   ![](https://api2.mubu.com/v3/document_image/50b23df2-1aff-4ea4-9aa1-4172671ea22e-11312918.jpg)
    *   Delegate/委托
        *   [委托 - C# 编程指南 | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/)
        *   [Unity游戏开发——对委托的理解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/84015453)
        *   Action<>
        *   委托简化写法
            *   Action<T>
                *   无返回类型的委托
            *   Func<T,outT>
                *   有返回类型的委托
            *   匿名方法
                *   Func<int,int,int> plus=delegate(int arg1,int arg2) { return arg1+arg2; }
            *   lambda表达式
                *   Func plus = (arg1, arg2) => {return arg1+arg2;} //lambda表达式的参数不需要声明类型
        *   exp
            *   *   ![](https://api2.mubu.com/v3/document_image/7006cd71-e977-4db1-83cc-eb3ecbbec218-11312918.jpg)
            *   *   ![](https://api2.mubu.com/v3/document_image/e77299b5-72b8-4efd-9843-8ceab18760bd-11312918.jpg)
            *   *   ![](https://api2.mubu.com/v3/document_image/36995738-ae3b-4805-8e81-3f0bcd715a37-11312918.jpg)
    *   EventHandler/事件
        *   事件是基于委托实现的
        *   [求大佬讲解下Unity的委托和事件的用法？ - 知乎 (zhihu.com)](https://www.zhihu.com/question/54482873/answer/254521411)
        *   EventArgs(是一个类)
            *   public class EventArgs{}
                *   如果我们要给事件附带的更多的信息（比如MouseEventArgs就附带的鼠标的各种状态），就需要自己写一个EventArgs的派生类
        *   EventHandler(是一个声明好的委托)
            *   当某个对象的某个事件或者是执行过程发生了，这个对象可以通过事件通知另外一个对象，另外一个对象可以通过传递进来的参数进行相应的处理；
            *   public delegate void EventHandler(object sender, TEventArgs e)
        *   定义事件触发分三步
            *   事件参数Class定义
                *   定义事件的参数
            *   事件Class定义
                *   定义一个事件对象
                *   定义可以触发此事件的函数
            *   使用Class定义
                *   定义事件处理函数
                *   定义一个事件Class变量
                *   对事件Class变量使用+=进行委托
                *   对事件Class变量调用可以触发此事件的函数
        *   exp
            *   参数的意思就是EventArgs中是否有数据
                *   *   ![](https://api2.mubu.com/v3/document_image/bbcaf8e3-010d-47b5-b9d0-b4da8c64dc7b-11312918.jpg)
                *   *   ![](https://api2.mubu.com/v3/document_image/6d169bc2-face-46b6-923a-925e43a9c498-11312918.jpg)
        *   触发事件可以有两种写法
            *   eventhandle(this,e)
            *   eventhandle.Invoke(this,e)
    *   嵌套类
        *   将一个类定义在另一个类的内部
    *   return&&break
        *   return
            *   跳出当前循环同时结束方法,return执行后方法结束
            *   该方法中循环结束以后的代码也不会执行
        *   break
            *   跳出当前循环,程序走到break这跳出当前循环,当前循环结束,继续执行循环外的代码
            *   break后面的代码不会执行
    *   转义字符
        *   [.NET 正则表达式中的字符转义 | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/character-escapes-in-regular-expressions)
            *   \\t 制表符
            *   \\n 换行符
            *   \\r 回车
    *   MemoryStream
        *   [MemoryStream 类 (System.IO) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.io.memorystream?view=net-5.0)
        *   [C#使用MemoryStream类读写内存](https://www.cnblogs.com/niyl/p/10137024.html)
    *   BitConverter
        *   [BitConverter 类 (System) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.bitconverter?view=net-5.0)
    *   正则表达式：正则表达式的主要作用是验证字符串的值是否满足一定的规则，在页面输入数据验证方面的应用比较多
        *   [Regex 类](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.regularexpressions.regex?view=net-5.0)
        *   Regex.ismatch:指示正则表达式在输入字符串中是否找到匹配项
        *   [正则表达式大全](https://blog.csdn.net/ZYC88888/article/details/98479629)
    *   Webclient
        *   [WebClient 类 (System.Net) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.webclient?view=net-5.0)
        *   UserAgent
            *   [HttpWebRequest.UserAgent 属性 (System.Net) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.httpwebrequest.useragent?view=net-5.0)
    *   WebRequest
        *   [WebRequest 类 (System.Net) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.webrequest?view=net-5.0)
    *   Stopwatch
        *   测量运行时间
            *   [Stopwatch 类 (System.Diagnostics) | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/api/system.diagnostics.stopwatch?view=net-5.0)
    *   ref&out
        *   *   ![](https://api2.mubu.com/v3/document_image/19d43730-74fa-420f-a268-de9ebc1a892b-11312918.jpg)
    *   static
        *   [static作用](https://q.cnblogs.com/q/113888/)  
    *   if(！A)
        * 表示条件不等于条件A时，执行
    *   object类型不能强制转换成int,可以使用 int.parse(object.tostring())
    *   [decimal](https://blog.csdn.net/u010771437/article/details/40867831)
    *   [float、double、decimal类型转换精度丢失](https://blog.csdn.net/starfd/article/details/44623335)
        * float:浮点型，含字节数为4，32bit，数值范围为-3.4E38~3.4E38（7个有效位）
        * double:双精度实型，含字节数为8，64bit数值范围-1.7E308~1.7E308（15个有效位）
        * decimal:数字型，128bit，28个有效位 
        * float 与计算机中数值表示方法有关,不是准确数据. decimal 是准确数据,不会出现这个问题
    *   方法返回不确定类型list
        * 返回固定List<int>类型
          * public static List<int> GetList(){}        
        * 返回List<T>类型 可以这样调用，GetList(1);此时返回List<int>类型
          * public static List<T> GetList<T>(T t){}
        * 返回List<T>类型 可以这样调用，GetList<int>();此时返回List<int>类型
            * public static List<T> GetList<T>(){}
        * 返回List<T>类型，并且T是可以实例化的类 /可以这样调用，GetList<DateTime>();此时返回的是List<DateTime>类型;不可以这样调用，GetList<int>();因为int类不能被实例化
            * public static List<T> GetList<T>() where T : new()
            * {
                * List<T> list = new List<T>();
                * T obj = new T();
                * list.Add(obj);
                * return list;
            * }
    *   C#数字转为百分数
        * deciaml percent = 0.123456789123456789M;
        * string q1 = percent.ToString("P"); //12.35%;自动四舍五入，百分数，千位分隔，自动两个小数
        * string q2 = percent.ToString("P0"); //12%；P后边跟数字，代表精度。
        * string q3 = percent.ToString("P1"); //12.3%；
        * string q4 = percent.ToString("P2"); //12.35%；
