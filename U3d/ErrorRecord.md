1、Assembly ‘Library/ScriptAssemblies/Unity.PlasticSCM.Editor.dll‘ will not be loaded due to errors
   ~ manifest.json 删除“com.unity.collab-proxy”:“1.9.0”，同时删除Library/PackageCache文件夹下的com.unity.collab-proxy@1.9.0文件，
   ~ https://blog.csdn.net/qq_41125597/article/details/127300290
2、Unity使用Aspose.Words.dll发布Windows平台后运行报错:Operation is not supported on this platform
   ~ Aspose.Words.Document doc = new Aspose.Words.Document(docPath);时报错，无法实例化获取Document对象。
   把脚本运行平台改为.NET 4.X
   ~ Document doc = Document()
   括号内路径不能为空，可以为一个空文件
3、项目中用到Aspose.Words.dll来操作word文件，出现ArgumentException
   ~ word模板文件损坏，新建word即可    
4、Aspose.word.dll要求system.drawing.dll、I18N.CJK、I18N、I18N.West.dll等文件版本必须一致
   ~ 所需dll已存至网盘
5、连接MySQL时，在unity编辑器里面运行没问题，但build后运行报异常：NotSupportedException: CodePage 1252 not supported
   ~ plugin 添加I18N.dll,I18N.West.dll文件
6、VS出现大量错误，但Unity项目正常运行
   ~ Edit->Projecting Settings->Player->Api Compatibility Level 切换两次
7、关于unity应用有些电脑带不动、卡顿问题
   ~ cpu 如果游戏卡顿的原因是CPU性能不足所导致的，那么会出现游戏运行缓慢、游戏画面卡顿、帧率低等现象。在这种情况下，您可以尝试升级CPU或者关闭一些其他占用CPU资源的程序，从而提升游戏性能。
   ~ Gpu 如果游戏卡顿的原因是GPU性能不足所导致的，那么会出现游戏画面不流畅，卡顿、画面花屏等现象。在这种情况下，您可以尝试升级GPU或者降低游戏画质设置，从而提升游戏性能。
   ~ 独立显卡是一种完全独立于CPU的显卡，它有自己的处理器、显存等硬件资源，能够提供更好的图像处理性能。在一些高端笔记本电脑和PC机中，独立显卡常常会采用双核设计，也就是说，显卡芯片内部包含双核处理器，可以同时进行多任务处理或者提高处理效率。常见的独立显卡品牌包括NVIDIA和AMD等。
   ~ 集成显卡则直接集成在CPU内部或者主板上，无法单独工作。由于其所依赖的CPU计算资源比较受限，因此集成显卡的性能往往较弱，仅能满足基本的图形显示需求。在一些高端CPU中，也可能会采用双核集成显卡设计，以提高其图形处理性能。
   所以尽量使用带有独显的电脑（NVIDIA的RTX,GTX）
8、unity5.5.2已经打包出去的应用程序，其分辨率及显示设置（projectsetting）会随着原工程打包出的其他应用程序发生变化
   ~ 可能是电脑自动配置的原因，电脑无法识别源工程打包出的不同应用程序，并以最新打包出的应用程序为准

