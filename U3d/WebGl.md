*   Webgl3D开发
    
    *   Unity&&Webgl
        *   [WebGL项目](https://baijiahao.baidu.com/s?id=1607426266434177655&wfr=spider&for=pc)
        *   案例
            *   2D
                *   [compliance/](https://segs.w3.uvm.edu/demos/compliance/)
                *   [InfraredEscape/](https://atmos.uw.edu/~dargan/EarthGamesUW/InfraredEscape/)
                *   [CorgiEngine](https://corgi-engine.moremountains.com/#demo)
            *   3D
                *   [Tanks/](https://www.wasm.com.cn/demo/Tanks/)
                    *   [Tanks](https://learn.unity.com/project/tanks-tutorial?language=en)
                *   [exhibits](https://ag.purdue.edu/exhibits/wp-content/games/Pharmaforce%20Fighters/index.html)
                    
        *   Web端屏幕自适应
            *   [webgl分辨率](https://blog.csdn.net/qq_38456478/article/details/78869971)
            
        *   web端打开链接
            *   Application.OpenURL ("http://www.xxx.com");
                *   此方法会把当前网页覆盖掉
            *   调用js,跳转到新网页
                *   unity+js
                    *   在jslib中采用window.open(Pointer\_stringify(url))直接打开网页
                *   unity+js+h5
                    *   jislib
                        *   window.open(h5\_url)
                    *   h5
                        *   打开新网页
                            *   <html> <head> <title>pageskip</title> <script language="javascript"> location.replace("[https://vehicles.ghac.cn](https://vehicles.ghac.cn/)") </script> </head> <body> </body> </html>
            *   unity webgl与jslib
                *   [Webgl和网页通信](https://blog.csdn.net/yuan9a/article/details/90640498)
                    
        *   webgl开发踩坑记
            *   [WebGL平台开发遇到的](https://www.codercto.com/a/72962.html)
            *   手机端打不开
                *   unity Resolution and Presentation 分辨率设置问题
                *   移动端不支持webgl2.0
                    *   [WebGL浏览器兼容性](https://docs.unity3d.com/cn/2019.4/Manual/webgl-browsercompatibility.html)
            *   部分电脑运行卡顿问题
                *   webgl限制帧率（不建议）
                    *   application.targerframerate=60
                *   Unity Profile进行分析
                    *   部分逻辑判断计算过多
                        *   vector3.distance()判断过多
                    *   垂直同步关闭（VSync）
                    *   EditorLoop
                        *   unity切换为默认布局,只在编辑器模式下存在
                            *   [stackoverflow](https://stackoverflow.com/questions/64494567/editor-loop-delay-is-it-a-problem-for-my-game)
                *   抗锯齿
            *   URP
                *   [Universal Render Pipeline](https://docs.unity3d.com/Packages/com.unity.render-pipelines.universal@7.1/manual/index.html)
            
        *   web端启动时间优化
            *   startup启动时间平均速度
                *   555k/s
                    *   startup time控制在20s,构建大小须<11M，asset<36M
            *   unity打包压缩设置
                *   unity-playersetting-publishsettings-compression format
                    *   brotli
                        *   包体最小，但是打包时间长
                    *   gzip
                        *   比brotli包体大，但是构建时间短
            *   assetbundle
                *   loading界面
            *   服务器本机浏览器解压缩
                *   [WebGL：部署压缩构建](https://docs.unity3d.com/cn/2019.4/Manual/webgl-deploying.html)
            
        *   webgl内存管理
            *   Unity2019已经弃用了WebGLMemorySize属性，改为自适应，内存加载峰值约2G
            *   造成卡顿的最大人物模型量
                *   unity内存及启动时间：大量的人物模型增加了内存，可以通过进入场景后再通过服务器加载的方式进行处理
                *   加载的模型会缓存到浏览器的内存中，但是人物模型内存很小，不影响
                *   人物过多，场景图形渲染、动画及逻辑计算增多，cpu占用率增多，不同客户端的图形渲染硬件会有限制。
        
    *   Ue4&&Webgl
        *   像素流的形式
            *   [UE4 Pixel Streaming](https://www.jianshu.com/p/879c69e647e2)
                
    *   Three.js&&Webgl
        *   介绍
            *   Three.js对于3D模型数据导入兼容不是很好，更适用于轻量级的3D场景，比如小游戏（微信跳一跳，支付宝的蚂蚁森林，蚂蚁庄园），展示性轻交互的广告类（淘宝天猫双11活动，红包活动等）。开发的时候花更多时间在模型数据兼容性上。
                
            *   对于大型的富交互的3D场景技术选型：WebAssembly + Unity3D(或Unreal) + Web三剑客（html + css + js）. 玩过Unity3D的应该知道，它打包时可以选择WebGL平台，原本用C#的语言编译成WebAssembly. 而三剑客们可以负责外围的页面渲染，数据交互，数据统计等，比如模型加载慢，用CSS + JS加强用户体验，模型加载的数据需要动态渲染，可以用JS和服务端交互获取数据然后传给模型等等。
        
    *   瓶颈
        *   1\. 客户端图形渲染的硬件限制
        *   2\. 3D模型场景下载的带宽限制