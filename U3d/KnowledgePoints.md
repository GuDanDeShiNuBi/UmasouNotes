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
                    *   设置锚点的同时设置UI中心点
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
        *   分别使用 \[0\]、\[1\]、\[2\] 访问 x、y、z 分量。
        
    *   获取模型中心点、范围盒
        *   [unity 获取包围盒](https://blog.csdn.net/u012909508/article/details/83014958)
        
    *   根据组件搜索物体
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
    *   调整exe窗口大小，projectsetting-Resolution and presentation-Resizable Window
    *   unity打开其他电脑或其他人的工程，vs会丢失unity相关引用：1、可以删除library,obj,logs文件夹重新打开；2、可以将源工程导出packages,然后新建工程打开导入，然后将projectsetting文件夹替换为源工程的
    *   输入框输入内容显示为星号，inputfield--content type改为password
        *   显示内容，则contenttype改为standerd
        *   限制inputfield输入内容设置contenttype即可