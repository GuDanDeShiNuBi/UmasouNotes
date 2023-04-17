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