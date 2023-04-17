*   Unity Mutiplayer
    *   利用SocketIO实现和Unity的通信
        *   [WebGL 集成 Socket.io](http://www.manew.com/thread-100354-1-1.html)
        *   [搭建一个简单的NodeJs服务器，利用SocketIO实现和Unity的通信](https://blog.csdn.net/wangjiangrong/article/details/80738778)
        *   [webgl加载assetbundle](https://bbs.huaweicloud.com/blogs/261580)
        
    *   Webgl网络
        *   无法直接访问套接字
        *   由于存在安全隐患，JavaScript 代码无法直接访问 IP 套接字来实现网络连接。因此，.NET 网络类（即 System.Net 命名空间中的所有内容，具体而言就是 System.Net.Sockets）在 WebGL 中不起作用。Unity 旧有的 UnityEngine.Network\* 类也是如此，以 WebGL 为构建目标时无法使用这些类。
        *   如果需要在 WebGL 中使用网络，当前可选择的做法是使用 Unity 中的 WWW 或 UnityWebRequest 类或使用支持 WebGL 的新型 [Unity 网络](https://docs.unity3d.com/cn/current/Manual/UNetOverview.html)功能，或者使用 JavaScript 中的 WebSockets 或 WebRTC 来实现您自己的网络。
        *   WebGL cannot act as a server. Use a Windows or other standalone platform build as the server. By default Unet on all platforms other than WebGL will use UDP for Unet's network transport, but WebGL is not capable of using UDP, only Websockets. So you tell the standalone build to use Websockets instead of UDP so WebGL clients can talk to it.
            *   [NetworkManager](https://docs.unity3d.com/cn/current/ScriptReference/Networking.NetworkManager-useWebSockets.html)
                
    *   服务端搭建
        *   nodejs
            *   安装步骤
                *   [node.js 安装详细步骤教程](https://blog.csdn.net/antma/article/details/86104068)
            *   node运行
                *   cmd---node+文件名.js
                    
    *   多人相机问题
        *   [Multiplayer Networking玩家独立相机跟踪](https://blog.csdn.net/l773575310/article/details/72677128)
            
    *   Mirror
        *   Unity2019后的版本弃用了unet(多人在线），所以其networkmanager等组件也不可使用了。现在大多数采用mirror插件来制作Multiplayer多人游戏。
        *   需挂载NetworkManager,NetworkManagerHUD,KCP Transport
        *   web端替换掉KCP Transport，使用“Simple Web Transport”
        *   人物需挂载 NetworkIdentity（确认人物唯一id），NetworkTransform（同步人物位置），NetworkAnimator(同步人物动画)
        *   NetworkBehaviour
            *   SyncMode
                *   By default synced data is sent from the server to all Observers of the object.\\nChange this to Owner to only have the server update the client that has ownership authority for this object
                *   SyncMode syncMode = SyncMode.Observers
                    *   默认情况下，同步数据从服务器发送给所有观察者对象
                *   SyncMode syncMode = SyncMode.Owner
                    *   同步数据仅从服务器发送给自己
            *   Authority
                *   clientAuthority
                    *   Set to true if moves come from owner client, set to false if moves always come from server
                    *   如果移动来自客户端设置为true，如何移动总是来自服务端设置为fasle
        *   NetworkManager
            *   OnSeverAddPlayer(NetworkConnection conn)
                *   当服务器有玩家加入时调用
                *   conn.identity
                    *   连接对象名称
                *   conn.connectionId
                    *   服务器唯一id
                *   conn.adress
                    *   连接地址
        
    *   帧同步与状态同步
        
        *   [两种同步模式：状态同步和帧同步](https://zhuanlan.zhihu.com/p/36884005)

* [游戏服务器引擎]https://kbengine.github.io/cn/