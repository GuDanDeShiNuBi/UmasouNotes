*   Contents
    *   ScriptingAPI
        *   [Unity - Scripting API: (unity3d.com)](https://docs.unity3d.com/ScriptReference/index.html)

    *   相机
        *   Unity Cinemachine
            *   [Unity Cinemachine 初识 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/103584975)
            *   可用于相机，也可用于固定轨迹移动的物体
            *   可结合timeline使用
        *   同一场景中可以同时存在多个maincamera,当只有一个处于激活状态时可通过camera.main查找。
        *   相机平缓跟随
            *   offset=transformposition-targetposition
            *   targetcameraposition=transformposition-offset
            *   vector3.lerp()
    *   unity内置建模插件
        *   ProBuilder
            *   [About ProBuilder | Package Manager UI website (unity3d.com)](https://docs.unity3d.com/Packages/com.unity.probuilder@4.0/manual/index.html?_ga=2.155842611.983271502.1548239858-1064638125.1532056217)
    *   协程
        *   介绍
            *   协程是一个能暂停执行，暂停后立即返回，直到中断指令完成后继续执行的函数。
            *   通过yield return，我们就能让他暂停在当前位置，然后直到有了返回在继续进行下面的代码。
    *   UI锚点🐱
        *   UI基本布局
            *   [基本布局 - Unity 手册 (unity3d.com)](https://docs.unity3d.com/cn/2019.4/Manual/UIBasicLayout.html)
        *   UI不同分辨率下的自适应
            *   [设计用于多种分辨率的 UI - Unity 手册 (unity3d.com)](https://docs.unity3d.com/cn/2019.4/Manual/HOWTO-UIMultiResolution.html)
        *   UI元素适用内容大小
            *   [使 UI 元素适应其内容的大小 - Unity 手册 (unity3d.com)](https://docs.unity3d.com/cn/2019.4/Manual/HOWTO-UIFitContentSize.html)
        *   锚点设置
            *   Anchor Presets
                *   also set pivot
                    *   设置锚点的同时设置UI中心点、
                *   also set position
                    *   设置锚点的同时设置UI位置
                *   图例
                    *   *   ![](https://api2.mubu.com/v3/document_image/5407f5af-718b-40e4-ad8d-4dcbce87c02f-11312918.jpg)
        
    *   ScrollView🛴
        *   content
            *   content节点下放子物体
            *   content通常挂载Vertical Layout Group、Horizontal Layout Group、Content Size Fitter
        *   scrollbar
            *   scrollbar.value=0
                *   滚动条滑到最底部
                    
    *   寻路
        *   [构建导航网格 - Unity 手册 (unity3d.com)](https://docs.unity3d.com/cn/2019.4/Manual/nav-BuildingNavMesh.html)
        *   Manual Voxel Size
            *   烘培准确度
                *   [高级导航网格烘焙设置 - Unity 手册 (unity3d.com)](https://docs.unity3d.com/cn/2019.4/Manual/nav-AdvancedSettings.html)
        
    *   透明遮挡
        *   [Unity Shader-遮挡处理（X-Ray，遮挡描边，遮挡半透，遮挡溶解）\_puppet\_master的专栏-CSDN博客](https://blog.csdn.net/puppet_master/article/details/73478905?utm_term=unity%E5%8D%8A%E9%80%8F%E6%98%8E%E9%81%AE%E6%8C%A1&utm_medium=distribute.pc_aggpage_search_result.none-task-blog-2~all~sobaiduweb~default-1-73478905&spm=3001.4430)
        
    *   时分秒
        *   hour =(int) time / 3600;
        *   //方案一
        *   //minuts = (int)((time - (hour \* 3600))/60);
        *   //seconds = (int)(time - hour \* 3600 - minuts \* 60);
        *   //方案二
        *   minuts =(int) time % 3600/60;
        *   seconds = (int)time % 3600 % 60;
        *   Debug.Log("hour:" + hour + " minuts:" + minuts + " seconds:" + seconds);
        
    *   game视图与scene视图同步
        *   ctrl+shift+f
            
    *   开关逻辑
        *   bool isopen;
        *   isopen=!isopen;
        
    *   ScriptableObject
        *   [ScriptableObject的介绍](https://blog.csdn.net/candycat1992/article/details/52181814)
        
    *   欧拉角转四元数
        *   Quaterniom.Euler(target\_angel)
        
    *   UGUI鼠标点击UI不受影响方法
        *   EventSystem.current.IsPointerOverGameObject()方法，作用：判断鼠标是否点击在UI上。
            
    *   确定一个plane
        *   //平面内一个+平面法向量
            *   public Plane(Vector3 inNormal, Vector3 inPoint);
        *   //平面法向量+长度
            *   public Plane(Vector3 inNormal, float d);
        *   //平面内任意不共线的三个点
            *   public Plane(Vector3 a, Vector3 b, Vector3 c);
        *   [https://blog.csdn.net](https://blog.csdn.net/m0_37763682/article/details/106367753)
        
    *   Plane.Raycast
        *   public bool Raycast(Ray ray, out float enter);
            *   判断射线是否和平面相交，并返回距离
            *   [Unity - Scripting API: Plane.Raycast](https://docs.unity3d.com/ScriptReference/Plane.Raycast.html)
        
    *   小数取整
        *   [Mathf](https://docs.unity3d.com/ScriptReference/Mathf.html).Ceil（float t）
            *   向上取整（返回大于或等于t的最小整数）
                *   1.02f=2
        *   Mathf.Round(float t)
            *   四舍五入
        *   Mathf.Floor(float t)
            *   向下取整（返回小于或等于t的最大整数）
                *   1.99f=1
                    
    *   正无穷向量
        *   [Vector3](https://docs.unity3d.com/ScriptReference/Vector3.html).positiveInfinity
        
    *   获取layer层级
        *   int layer=LayerMask.GetMask("UI")
        
    *   对象池
        *   [OBJECT POOLING in Unity - YouTube](https://www.youtube.com/watch?v=tdSmKaJvCoA)
        
    *   get/set属性访问器
        *   [Get/Set属性访问器](https://blog.csdn.net/Mr_Sun88/article/details/84202382)
        
    *   Transform/Gameobject.find
        *   GameObject.Find()
            *   1.GameObject只能查找到active的物体
            *   2.如果name指定路径，则按路径查找；否则递归查找，直到查找到第一个符合条件的GameObject或者返回null
        *   Transform.Find()
            *   transform.Find用于查找子节点，它并不会递归的查找物体，也就是说它只会查找它的子节点，并不会查找子节点的子节点。
        
    *   Vector\[int\]
        *   分别使用 \[0\]、\[1\]、\[2\] 访问 x、y、z 分量 
        
    *   获取模型中心点、范围盒
        *   [unity 获取包围盒](https://blog.csdn.net/u012909508/article/details/83014958)
        
    *   根据组件搜索物体//
        *   在Hierarchy面板上出来可以使用名称进行搜索到指定的物体外，还可以使用t:组件名 （如:t:boxcollider）来获取所有带有这个组件的游戏
        
    *   [Physics2D](https://docs.unity3d.com/cn/2019.4/ScriptReference/Physics2D.html).OverlapCircle
        *   [Physics2D-OverlapCircle](https://docs.unity3d.com/cn/2019.4/ScriptReference/Physics2D.OverlapCircle.html)
        *   [UNITY2d检测方法OverlapCircle与Raycast详解](http://www.voycn.com/article/unity2djiancefangfaoverlapcircleyuraycastxiangjie)
        
    *   UI不规则区域点击
        *   [Untiy实用功能之UGUI不规则的按钮点击](https://juejin.cn/post/7000387760078979080)
    *   设置UI优先级
        *   transform.SetAsLastSibling\SetAsFirstSibling
    *   RectTransform
        *   [RectTransform详解1](https://www.jianshu.com/p/4592bf809c8b)
        *   [RectTransform详解2](https://zhuanlan.zhihu.com/p/139252379)
       
    *   动态列表
        *   [unity动态列表](https://blog.csdn.net/linxinfa/article/details/122019054) 
       
    *   调整exe窗口大小
        *   projectsetting-Resolution and presentation-Resizable Window
          
    *   unity打开其他电脑或其他人的工程，vs会丢失unity相关引用
        *   1、可以删除library,obj,logs文件夹重新打开
        *   2、可以将源工程导出packages,然后新建工程打开导入，然后将projectsetting文件夹替换为源工程的

    *   输入框输入内容显示为星号，inputfield--content type改为password
        *   显示内容，则contenttype改为standerd
        *   限制inputfield输入内容设置contenttype即可
         
    * [unityAction、Action、Delegate、Reflection](https://www.cnblogs.com/pz904/p/12596606.html)
    
    * [unity调用windows系统对话框保存](https://blog.csdn.net/abc1090275833/article/details/88058679 )
    
    * [加解密](https://www.cnblogs.com/guhuazhen/p/11201450.html)
      * 可逆：RSA,AES,DES等,  不可逆：常见的MD5，SHAD等
      * Des加解密：密钥长度必须为8位。[des](https://www.zhihu.com/question/36767829)
      
    * Unity Inputfield 被选中后未显示光标（caret）
      * 解决：将Inputfield的子节点Placeholder与Text组件RectTransform大小设置一致
      * 分辨率太小，光标也会不显示可将Inputfield的Caret width 调大
      
    * [Table键切换输入框](https://blog.csdn.net/qq_42937284/article/details/106146595)
    * [scrollview滚动到指定位置](https://blog.csdn.net/qq_42672770/article/details/122611935)
      * GetComponent<ScrollRect>().normalizedPosition = new Vector2(0, 0);new Vector2(0,1)
     
    * 设置Sprite Editor，使UI拉伸时边缘不变形
    * projectsetting---Fixed Timestep=0.02:代表每帧为0.02秒，所以1秒=50帧
  
    * [unity安装包制作](https://blog.csdn.net/qq_42194657/article/details/99614051)
    * UI——Navigation组件：用于UI导航，切换按钮。当关闭此选项后，Button会无法聚焦（无法响应其selected color等状态）
   
    * 如何让按钮保存选中状态
      * 1、修改按钮颜色，程序修改
      * 2、使用toggle,toggle group [toggle](https://blog.csdn.net/a1208498468/article/details/117016149)
     
    * list使用前需要先初始化，创建实例,否则会报空指针。可在声明时进行，如list<T>myList=new list<T>();
    * UI子节点锚点问题
      * 子节点的锚点设置以自身父节点位置大小为基础
      
    * 预制体文件损坏怎么办：将该预制体.meta文件的后缀改为.prefab即可恢复

    * unity分辨率设置，projectsetting-resolution and presentation-display resolution dialog选项在 Unity2019之后的版本去除
    
    * unity设置为全屏模式后，无法设置窗口大小。
      * 需要调整为windowed模式，这个模式带有windows边框，需要做去边框操作
      
    * unity抗锯齿
      * canvas设置为screen space -camera, camera打开msaa,quality setting里设置anti Aliasing 2x\4x\8x

    * unity汉化
      * 把语言包文件(zh-cn.po)放在Unity的安装目录下：C:\Program Files\Unity\2018.4.9f1\Editor\Data\Localization\
       如果没有这目录，则自己新建一个，注意文件名为zh-cn.po

    * [协程终止问题](https://blog.csdn.net/C_Han_Dong/article/details/113458471)

    * 如何设置一个未选择的（默认值为空）的下拉列表dropdown
      * 下拉列表添加一个默认项default，list<string> temp=new list<string>{"1","2","3","default"};
      * 初始化dropdown： dropdown.addoptions(temp);
      * 选择default为默认值:  dopdown.value=dopdown.options.Count - 1;
      * 移除default:  dopdown.options.RemoveAt(dopdown.options.Count - 1)
      * 最后在事件监听时设置text:dropdown.onValueChanged.AddListener(value =>{  if (dropdown.options[value].text == "default")
                return;});
                
    * getComponent<T>可以看做是一个获取对象实例的过程，T看做为一个类

    * unity内存详解 
      * [unity内存过大](https://zhuanlan.zhihu.com/p/336004123)

    * 快速进行UI设置    
      * [预设UI](https://blog.csdn.net/weixin_32848617/article/details/112416558)
      * [unity UI快速排版对齐](https://blog.csdn.net/cheng624/article/details/72648768)

    * [模型拆分效果实现](https://blog.csdn.net/xiaochenXIHUA/article/details/93851373)

    * unity打开vs，一直显示Importing assets。
      * 原因：工程路径中存在中文



    * [导入模型&&blender结合unity](https://blog.csdn.net/linxinfa/article/details/121370565?spm=1001.2100.3001.7377&utm_medium=distribute.pc_feed_blog_category.none-task-blog-classify_tag-9-121370565-null-null.nonecase&depth_1-utm_source=distribute.pc_feed_blog_category.none-task-blog-classify_tag-9-121370565-null-null.nonecase)
    
    * [unity工程被高版本打开报错](https://blog.csdn.net/qq_34342853/article/details/120564273)
      * 找到项目根目录/Packages/manifest.json，删掉相应的行即可

    *  宏定义：在不同的环境下执行不同的代码，比如在安卓平台和在苹果平台下执行不同的代码，这样你就可以专门为你的目标平台编译代码
       *  [unity宏定义](https://blog.csdn.net/baidu_39447417/article/details/78295734) 
       *   1. UNITY_EDITOR       Unity编辑器中调用
           1. UNITY_ANDROID      安卓平台
           2. UNITY_IPHONE       苹果平台。
           3. UNITY_STANDALONE   独立的平台（Mac，Windows或Linux）
    *  [unity帧率](https://cloud.tencent.com/developer/article/1894207)

    *   [https://blog.csdn.net/cwj649956781/article/details/76218218](https://blog.csdn.net/cwj649956781/article/details/76218218)
        *   https://www.jianshu.com/p/22a927dc0ba2

    *   UnityEngine.Mathf.Repeat与Mathf.PingPong
        *   https://blog.csdn.net/qq_15505341/article/details/79251558
    
    *   Unity连接Mysql,默认情况下使用的是短连接。如果需要使用长连接，需要在建立连接时设置连接选项，将Connection Timeout的值设置为0或较大值即可

    *  unity canvas的match。https://zhuanlan.zhihu.com/p/643275125
    
    *  unity应用程序转成安装包  
       *  https://blog.csdn.net/linxinfa/article/details/105863615  
    
    *  unity查询mysql数据，select结果按列中时间 来排序
       *  SELECT * FROM your_table_name  ORDER BY your_datetime_column ASC;ASC 是升序排列，DESC 是降序排列
       *  如果日期时间数据存储为字符串（例如 VARCHAR），排序可能会出现问题。需要将其转换为日期时间类型。
          *  CAST 函数可以将 VARCHAR 类型转换为 DATETIME 类型：
          *  SELECT *FROM your_table_name ORDER BY CAST(your_varchar_column AS DATETIME) DESC;
   
    *  unity如何将rendertexture的显示呈现的长方形带有弧度
       *  RawImage放在带有mask组件的image下能被遮挡
       *  mask组件的主要功能是限制其子对象的可见范围，使得子对象只能在Mask组件指定的区域内显示

    *  UNITY中启动一个线程
       *  1、使用Tread 适用于.net早版本
       *  using System.Threading;
       *  backgroundThread = new Thread(Task);
       *  void Task(){
       *  //执行线程任务，大都为一些数据交互
       *  Thread.Sleep(5000)//控制任务的执行间隔或延迟任务的开始
       *  }；
       *  线程内不能直接调用 Unity 的主线程 API,因为Unity 的主线程是处理所有游戏对象、组件和渲染的唯一线程。其 API 和操作是线程不安全的
       *  2、使用Task 适用于.net4
       *  using System.Threading.Tasks;
       *  async void Start(){// 启动异步任务 await RunInTaskAsync();}//为什么Start()方法也要async,为了使用 await 关键字来等待异步操作完成
       *  private async Task RunInTaskAsync(){//执行后台任务  //模拟耗时await Task.Delay(2000);//更新 Unity 主线程的 UI 或对象UpdateMainThread（）；}
       *  private void UpdateMainThread(){// 在主线程中更新 Unity 相关操作}
    
    *   unity导入obj模型时，无法关联mtl材质文件
        *  用文本编辑器打开 OBJ 文件
        *  在 OBJ 文件中搜索mtllib关键字，该指令用于指定 MTL 文件的路径（如：mtllib model.mtl），这表示 MTL 文件与 OBJ 文件在同一目录下，且名为model.mtl
        *  若路径包含空格或特殊字符（如中文），可能导致 Unity 无法正确解析，需要将mtl文件及obj文件重命名

    *   unity场景过暗，模型过暗
        *   未勾选 Windows-Rendering-Lighting-Auto Generate
        *   光照烘焙仅对标记为 Static 的物体生效，产生光照贴图文件
        *   即使没有静态物体烘焙光照贴图，场景变亮可能由以下原因导致：1、实时光源（Realtime Lights）：若光源的 Mode 设置为  Realtime，则其光照效果会在运行时实时计算（如直接光照、阴影），不依赖烘焙。2、实时全局光照（Realtime GI）：
        在 Lighting Settings 中启用 Realtime Global Illumination 后，Unity 会使用光照探针（Light Probes）或反射探针（Reflection Probes）计算动态物体的间接光照，即使没有静态物体烘焙，也可能让场景显得更明亮
        *   打包后效果依然保留 

    *   if (_videoSlider)是正确的，if (xx != null)的话就存在问题
        *   Unity 中的绝大多数对象（如GameObject、Component、Texture等）都继承自 Unity 引擎自定义的UnityEngine.Object类，而非 C# 原生的System.Object。
        *   if (_videoSlider) 当_videoSlider是 Unity 的Object派生类（比如Slider组件）时，if (_videoSlider)实际上调用的是 Unity 重写的bool运算符，它会：检查对象是否被标记为 “已销毁”（即使 C# 层面的引用还未置为null）。检查对象是否在内存中真实有效（例如避免 “僵尸对象”—— 已销毁但引用未清空的对象）。
        *   if (xx != null)  C# 原生的xx != null判断的是 “引用是否指向内存中的某个地址。当 Unity 对象被销毁（如调用Destroy()）后，C# 层面的引用可能不会立即变为null。