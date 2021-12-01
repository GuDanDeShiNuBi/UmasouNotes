*   UnityGameFrameWork
    *   参考资料
        *   [笨木头与游戏开发 (benmutou.com)](http://www.benmutou.com/archives/2548)
        *   [GameFramework篇：StarForce学习笔记 | 烟雨迷离半世殇的成长之路 (lfzxb.top)](https://www.lfzxb.top/gameframework-starforce/)
        *   [UGF游戏框架实例开发教程\_道友请留步-CSDN博客](https://blog.csdn.net/qq_32821435/category_7753219.html)
    *   GameEntry
        *   获取基础组件，unitygameframework.gameentry.getcomponent<T>
        *   初始化自带基础组件与自定义组件
    *   ProcedureBase
        *   \*\*流程 (Procedure)\*\* – 是贯穿游戏运行时整个生命周期的有限状态机。通过流程，将不同的游戏状态进行解耦将是一个非常好的习惯。对于网络游戏，你可能需要如检查资源流程、更新资源流程、检查服务器列表流程、选择服务器流程、登录服务器流程、创建角色流程等流程，而对于单机游戏，你可能需要在游戏选择菜单流程和游戏实际玩法流程之间做切换。如果想增加流程，只要派生自 ProcedureBase 类并实现自己的流程类即可使用。
        *   增加流程，只要派生自 ProcedureBase 类并实现自己的流程类即可使用
        *   在流程类中的OnUpdate()中来切换流程ChangeState<Procedure\*\*\*\*>(procedureOwner);
        *   在流程类的OnEnter()中来切换场景，订阅事件GameEntry.Event.Subscribe(LoadSceneSuccessEventArgs.EventId, OnLoadSceneSuccess); GameEntry.Scene.LoadScene("Assets/GameMain/Scenes/MainScene.unity", this);
        *   切换流程则直接进入要切换的流程类脚本
        *   *   ![](https://api2.mubu.com/v3/document_image/aac0e60a-a417-49cb-84b8-d63f6ce8b99b-11312918.jpg)
*   UI
    *   UI部分采用MVC模式开发，逻辑与显示模块分离
    *   UI搭建注意层次分级与动静分离
*   开发流程
    *   确定本项目基础流程
        *   登录--注册--创建角色--进入游戏--加载资源--主场景