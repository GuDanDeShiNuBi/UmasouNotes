### GameFrameWork架构

#### 参考
[花桑](https://www.zhihu.com/column/c_1436501161410596864)
[Demo](https://github.com/DrFlower/TowerDefense-GameFramework-Demo)
[烟雨](https://www.lfzxb.top/gameframework-starforce/)
[设计模式](https://gpp.tkchu.me/state.html)
[委托&事件](https://www.cnblogs.com/SkySoot/archive/2012/04/05/2433639.html)
[思维导图](https://boardmix.cn/app/editor/Oczxc_30Ld1-_X17W-tPTg?inviteCode=DzoloB)

#### 计划
* vscode 记录学习过程、总结相关知识经验
* github 存储项目工程文件
* 数据结构，算法，设计模式，渲染管线，网络协议，操作系统，组成原理
* 2D像素游戏
  * 相机：cinemachine(2D)
  * 动画：2D animation
  * 图片处理：2D SpriteShape
  * 地形布局：Tilemap


#### Knowledge
* 有限状态机
* 回调函数
* 事件
  * https://www.cnblogs.com/neverdie/p/Unity3D_event_delegate_1.html
  * 关于事件：基本上是用于解耦的，举一个比较实在的例子：
    在游戏中，我们要知道是否有怪物死亡，一旦有怪物死亡，我们就需要更新UI上的怪物剩余数量、更新英雄的经验值、做其他我们希望做的事情。
    实现这种需求，我们可以简单地循环怪物列表，如果发现了状态为Dead的怪物，就进行以上的操作。
    但是这样会有很多问题，一个是效率低，另一个是让不同类型的操作耦合在一起了（因为以上的各种操作都需要在找出死亡怪物时执行）。
    而用事件订阅可以将以上主动的操作转换为被动，我们不需要遍历怪物列表，我们只需要在各个不同的地方订阅怪物死亡消息。
    当怪物死亡时，它自己发出一个怪物死亡消息即可，至于谁要做什么操作，怪物不用管，各自的订阅者会执行自己的逻辑。
    目前来说，如果没有事件订阅机制，我基本上写不出游戏了
* 事件池
  * 引用池
  * 对象池 
    * https://www.cnblogs.com/mezero/p/3955130.html
    * http://www.xuanyusong.com/archives/2974
* 泛型类型约束
  * new
  * where
* Effective C#提炼总结，提高代码质量
  * https://zhuanlan.zhihu.com/p/24553860


##### 引用池
* IReference:引用接口

* ReferencePool:引用池
  * 静态类

* ReferenceCollecion
  * ReferencePool的私有类

* ReferencePoolInfo：引用池信息
  * 结构体
  * 