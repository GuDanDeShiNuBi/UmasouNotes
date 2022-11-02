*   unity网络编程
    *   概述
        *   Unity通讯一般分为2类
            *   Http : 应用层 Unity内置的UnityWebRequest类进行通信，用于交互量比较小
            *   Socket：传输层 比较底层 实现TCP/UDP 用于频繁的通信
        
    *   网络层次
        *   OSI七层模型（OSI国际标准化组织）
            *   各层描述
                *   应用层：为操作系统或网络应用程序提供访问网络服务的接口。
                    *   基本数据单位
                        *   报文
                    *   主要协议
                        *   FTP（文件传送协议）
                        *   Telnet（远程登录协议）
                        *   DNS（域名解析协议）
                        *   SMTP（邮件传送协议）
                        *   POP3协议（邮局协议）
                        *   HTTP协议（Hyper Text Transfer Protocol）
                *   表示层：数据的压缩优化加密
                *   会话层：建立用户级的连接，选择适当的传输服务
                *   传输层：网关 传输层负责将上层数据分段并提供端到端的、可靠的或不可靠的传输以及端到端的差错控制和流量控制问题
                    *   主要协议
                        *   TCP协议（Transmission Control Protocol，传输控制协议）
                        *   UDP协议（User Datagram Protocol，用户数据报协议）
                *   网络层：路由器 网络层负责对子网间的数据包进行路由选择，还可以实现拥塞控制、网际互连等功能
                    *   基本数据单位
                        *   IP数据报
                    *   协议
                        *   IP协议（Internet Protocol，因特网互联协议）
                        *   ICMP协议（Internet Control Message Protocol，因特网控制报文协议）
                        *   ARP协议（Address Resolution Protocol，地址解析协议）
                        *   RARP协议（Reverse Address Resolution Protocol，逆地址解析协议）
                *   链路层：网桥、交换机 数据链路层为网络层提供可靠的数据传输
                    *   基本数据单位
                        *   帧
                    *   主要协议
                        *   以太网协议
                *   物理层：中继器、集线器 该层为上层协议提供了一个传输数据的可靠的物理媒体
            *   图解
                *   *   ![](https://api2.mubu.com/v3/document_image/7f257e96-af51-4f93-a131-e112be29e411-11312918.jpg)
                *   *   ![](https://api2.mubu.com/v3/document_image/1f93ba44-831f-45dc-ab02-2cfded992d28-11312918.jpg)
        
    *   TCP/IP协议
        *   描述
            *   Internet最基本的协议
            *   TCP负责发现传输的问题，一有问题就发出信号，要求重新传输，直到所有数据安全正确地传输到目的地。
            *   可靠的协议 通过三次握手建立的面向连接通信协议
        *   TCP报文段的首部格式
            *   *   ![](https://api2.mubu.com/v3/document_image/7d624b1d-4d03-4957-8935-7a512a1df2ef-11312918.jpg)
        *   TCP连接与断开
            *   TCP连接建立过程（三次握手）
                *   目的：防止因为网卡导致Sever收到多次Client请求 建立N个监听 造成资源浪费
                *   1.首先Client端发送连接请求报文
                *   2.Server段接受连接后回复ACK报文，并为这次连接分配资源。
                *   3.Client端接收到ACK报文后也向Server段发生ACK报文，并分配资源，这样TCP连接就建立了。
            *   TCP连接断开过程(四次挥手)
                *   目的：自己不请求直接关闭 但是服务器还能给你发数据 服务器浪费资源 而且客户端也会强行接收
                *   1.Client端发起中断连接请求(FIN报文)
                *   2.Server端接到FIN报文后，发送ACK服务器还有消息没发完让Client待命，Client端就进入FIN\_WAIT，继续等待Server端的FIN报文
                *   3.Server端确定数据已发送完成，则向Client端发送FIN报文，
                *   4.Client端收到FIN报文后发送ACK后进入TIME\_WAIT状态，如果Server端没有收到ACK则可以重传，Server端收到ACK后 关闭，Client等待了2MSL后依然没有收到回复客户端也关闭
            *   图解
                *   *   ![](https://api2.mubu.com/v3/document_image/3523a0c7-eaf3-4ae5-a8b6-f084742e0eee-11312918.jpg)
                *   SYN:"synchronize"请求同步标志；；ACK:"acknowledge"确认标志"；FIN："Finally"结束标志。
            *   [tcp/ip协议三次握手、四次挥手](https://blog.csdn.net/weixin_43303455/article/details/119899706?utm_medium=distribute.pc_feed_v2.none-task-blog-hot-13.pc_personrecdepth_1-utm_source=distribute.pc_feed_v2.none-task-blog-hot-13.pc_personrec)
        *   使用TCP的协议：FTP（文件传输协议）、Telnet（远程登录协议）、SMTP（简单邮件传输协议）、POP3（和SMTP相对，用于接收邮件）、HTTP协议等。
    *   UDP协议
        *   描述
            *   面向无连接的通讯协议
            *   UDP通讯时不需要接收方确认，属于不可靠的传输 会丢包
            *   UDP与TCP位于同一层，但它不管数据包的顺序、错误或重发
            *   主要用于面向查询---应答的程序
            *   每个UDP报文分UDP报头和UDP数据区两部分
        *   使用UDP协议包括：TFTP（简单文件传输协议）、SNMP（简单网络管理协议）、DNS（域名解析协议）、NFS、BOOTP。
    *   HTTP协议
        *   描述
            *   超文本传输协议（HTTP，HyperText Transfer Protocol)是互联网上应用最为广泛的一种网络协议
            *   *   ![](https://api2.mubu.com/v3/document_image/6d753c8c-ad10-444e-a3ca-3f6dc0481bfb-11312918.jpg)
        *   过程
            *   1.客户端浏览器通过DNS解析(URL转换为IP地址)到[www.baidu.com](https://links.jianshu.com/go?to=http%3A%2F%2Fwww.baidu.com)的IP地址220.181.27.48，通过这个IP地址找到客户端到服务器的路径。客户端浏览器发起一个HTTP会话到220.161.27.48，然后通过TCP进行封装数据包，输入到网络层。
            *   2.在客户端的传输层，把HTTP会话请求分成报文段，添加源和目的端口，如服务器使用80端口监听客户端的请求，客户端由系统随机选择一个端口如5000，与服务器进行交换，服务器把相应的请求返回给客户端的5000端口。然后使用IP层的IP地址查找目的端。
            *   3.客户端的网络层通过查找路由表确定如何到达服务器，期间可能经过多个路由器。
            *   4.客户端的链路层，包通过链路层发送到路由器，通过邻居协议查找给定IP地址的MAC地址，然后发送ARP请求查找目的地址，如果得到回应后就可以使用ARP的请求应答交换的IP数据包现在就可以传输了，然后发送IP数据包到达服务器的地址。
        *   特点
            *   简单快速 灵活 无连接 无状态 支持B/S(浏览器/服务器)及C/S(客户端/服务器)模式。
            *   *   ![](https://api2.mubu.com/v3/document_image/17bd6f56-d971-47e7-b0d4-72bcc9a5761f-11312918.jpg)
            
    *   Socket套接字
        *   描述
            *   和服务器有一些频繁的交互 用http时不时请求 叫轮询 效率低下
            *   soket可以理解为插座 插头接上了可以保持通信
        *   [Socket 类](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.sockets.socket?view=net-5.0)
        *   *   ![](https://api2.mubu.com/v3/document_image/d48e2233-6783-43b8-8efc-98da7095ba85-11312918.jpg)
        *   IPAdress.Parse
            *   [IPAddress.Parse 方法](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.ipaddress.parse?view=net-5.0)
            *   将 IP 地址字符串转换为 [IPAddress](https://docs.microsoft.com/zh-cn/dotnet/api/system.net.ipaddress?view=net-5.0) 实例。
        *   System.Text.Encoding.UTF8.GetString()
            *   将一个字节序列解码为一个字符串。
            *   [Encoding.GetString](https://docs.microsoft.com/zh-cn/dotnet/api/system.text.encoding.getstring?view=net-5.0)
        *   System.Text.Encoding.Default.GetBytes(字符串)
            *   把字符串转换成byte\[\]数组
        *   socket.Listen(int backlog)
            *   参数backlog指定队列中最多可容纳等待接受的连接数，0表示不限制
        *   粘包拆包
            *   [分包和粘包二](https://blog.csdn.net/yang854426171/article/details/88764319?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-3)
    *   拓展
        *   网址，URL，域名，IP地址，DNS，域名解析
            *   [https://cloud.tencent.com/developer/article/1623575](https://cloud.tencent.com/developer/article/1623575)
    *   WebSocket
        *   描述
            *   是一种在单个TCP连接上进行[全双工](https://baike.baidu.com/item/%E5%85%A8%E5%8F%8C%E5%B7%A5)通信的协议。
            *   WebSocket使得客户端和服务器之间的数据交换变得更加简单，允许服务端主动向客户端推送数据。
        *   unity结合websocket使用
            *   [Unity3d 下websocket的使用](https://blog.csdn.net/leoleocs/article/details/48824921)

*  计算机网络通信相关
   *  [地址与端口](https://blog.csdn.net/qq_41122796/article/details/80287340)