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
* 委托、事件、回调
  * 委托：本质是 "函数指针的容器"，定义了回调函数的参数和返回值格式
  * 事件：基于委托的封装
    * https://www.cnblogs.com/neverdie/p/Unity3D_event_delegate_1.html
    * 关于事件：基本上是用于解耦的，举一个比较实在的例子：
      在游戏中，我们要知道是否有怪物死亡，一旦有怪物死亡，我们就需要更新UI上的怪物剩余数量、更新英雄的经验值、做其他我们希望做的事情。
      实现这种需求，我们可以简单地循环怪物列表，如果发现了状态为Dead的怪物，就进行以上的操作。
      但是这样会有很多问题，一个是效率低，另一个是让不同类型的操作耦合在一起了（因为以上的各种操作都需要在找出死亡怪物时执行）。
      而用事件订阅可以将以上主动的操作转换为被动，我们不需要遍历怪物列表，我们只需要在各个不同的地方订阅怪物死亡消息。
      当怪物死亡时，它自己发出一个怪物死亡消息即可，至于谁要做什么操作，怪物不用管，各自的订阅者会执行自己的逻辑。
  * 回调：符合委托签名的函数，注册到事件后，会在事件触发时被自动调用。相当于我们提前把函数交给系统，告诉系统 “等某个事件发生时，就用这个函数来回应用户”，所以叫 “回调”（回头调用）。
  
  * 具体实现（通过一个 "玩家生命值变化" 的场景演示：当玩家生命值变化时，UI 面板更新显示，同时日志系统记录变化）
    * 1、 定义委托和事件（事件发布者）
        ```C#
        using UnityEngine;
                  // 1. 定义委托（规定回调函数的签名：参数为新生命值，无返回值）
                  public delegate void OnHealthChanged(int newHealth);
                  public class PlayerHealth : MonoBehaviour
                  {
                      private int _currentHealth;
                      // 2. 基于委托定义事件（事件名通常以On开头）
                      public event OnHealthChanged HealthChangedEvent;
                      public void TakeDamage(int damage)
                      {
                          _currentHealth = Mathf.Max(0, _currentHealth - damage);        
                          // 3. 触发事件（仅在有回调注册时执行）
                          if (HealthChangedEvent != null)
                          {
                              HealthChangedEvent(_currentHealth); // 传递新生命值给所有回调
                          }
                      }
                  }
        ```
    * 2、编写回调函数并注册（事件订阅者）
      * UI 显示脚本（UIManager）：
        ```C#
        using UnityEngine;
                    using UnityEngine.UI;
                    public class UIManager : MonoBehaviour
                    {
                        public Text healthText;
                        private PlayerHealth _playerHealth;
                        private void Start()
                        {
                            // 获取PlayerHealth实例
                            _playerHealth = FindObjectOfType<PlayerHealth>();
                            // 4. 注册回调函数到事件（当事件触发时，UpdateHealthUI会被调用）
                            _playerHealth.HealthChangedEvent += UpdateHealthUI;
                        }
                        // 回调函数（必须符合OnHealthChanged委托的签名）
                        private void UpdateHealthUI(int newHealth)
                        {
                            healthText.text = $"生命值: {newHealth}";
                        }
                        // 5. 移除回调（避免对象销毁后事件触发导致空引用错误）
                        private void OnDestroy()
                        {
                            if (_playerHealth != null)
                            {
                                _playerHealth.HealthChangedEvent -= UpdateHealthUI;
                            }
                        }
                    }
        ```

  * 关于事件的触发背后并不是 “持续监听某个函数是否变化”，而是基于一种更高效的 “被动通知” 机制 —— 只有当特定条件满足时，事件才会被主动触发，进而执行所有注册的回调函数。这种方式不需要每帧消耗性能。
    * 事件机制的本质是 **“发布 - 订阅模式”**，核心逻辑可以拆解为 3 步：
      * 1、订阅阶段：订阅者（如UIManager）将自己的回调函数（如UpdateHealthUI）“注册” 到发布者（如PlayerHealth）的事件列表中。
        这一步只是 “记录函数地址”，不会产生任何持续的 “监听” 行为。
      * 2、触发条件满足：当发布者内部发生特定行为（如玩家受到伤害、生命值变化）时，开发者在代码中手动编写 “触发事件” 的逻辑（如 HealthChangedEvent(_currentHealth)）。这个触发完全是 “主动的”—— 只有当开发者明确调用触发代码时，事件才会被激活，不存在  “自动监听函数是否变化” 的过程。
      * 3、通知所有订阅者：事件被触发时，发布者会遍历自己维护的 “回调函数列表”，依次执行所有注册的函数
      * 具体实现如：
         ```C#
              // 1. 模拟委托：本质是一个"方法容器"，存储多个方法的引用
                               public class MyDelegate
                               {
                                   // 用列表存储"函数地址"（实际是方法的引用）
                                   private List<Action<int>> _methodList = new List<Action<int>>();
                                   // 2. 模拟 "+=" 操作：添加函数到列表（记录函数地址）
                                   public void Add(Action<int> method)
                                   {
                                       _methodList.Add(method);
                                   }
                                   // 3. 模拟 "-=" 操作：从列表移除函数
                                   public void Remove(Action<int> method)
                                   {
                                       _methodList.Remove(method);
                                   }
                                   // 4. 模拟事件触发：依次调用列表中的所有函数
                                   public void Invoke(int value)
                                   {
                                       foreach (var method in _methodList)
                                       {
                                           method(value); // 调用记录的函数
                                       }
                                   }
                               }
         ```
  
  * 关于委托、事件、Action、EventHandler<T>、Func<T> 区别
    * 委托是 “方法容器”：灵活但缺乏封装，适合内部逻辑的方法传递。外部访问权限：公开的委托变量，外部可直接执行赋值（=）、调用（Invoke）、添加 / 移除方法（+=/-=）。
    * 事件是 “委托的安全封装”：通过限制外部操作（仅允许订阅 / 取消），确保 “发布 - 订阅” 模式的安全性，是模块间通信的最佳实践。外部访问权限：外部仅允许添加（+=） 或移除（-=） 方法订阅，不允许直接赋值（=）或调用（Invoke），只能在声明类内部触发。
    * Action是 C# 预定义的无返回值泛型.委托（System.Action），可直接作为 “委托类型” 或 “事件的底层委托类型”，简化代码（无需手动声明委托）。作为 “委托类型”：public delegate void OnHealthChanged(int newHealth);public event OnHealthChanged HealthChangedEvent;作为事件的底层委托类型：public event Action<string> OnMessage; 
    * EventHandler<T>是 C# 中预定义的泛型委托类型（位于 System 命名空间），是 .NET 框架中处理事件的标准委托类型之一。
      * 官方定义：public delegate void EventHandler<TEventArgs>(object sender, TEventArgs e) 
      where TEventArgs : EventArgs;// TEventArgs 必须继承自 EventArgs（事件数据基类）
      * EventHandler<T> 是事件的 “底层委托类型”，事件需要基于它来声明。 public event EventHandler<PlayerAttackEventArgs> OnAttack;
      * 与Action<T>区别
        * |   | EventHandler<TEventArgs>   |  Action<T> |
          | :------- | :------: | :-------: |
          |  参数规范| 固定两个参数：sender（事件源）和 e（事件数据） | 可自定义参数（0~16 个），无固定规范 |
          | 事件数据约束 | TEventArgs 必须继承自 EventArgs（遵循 .NET 规范） | 无约束，可使用任意类型 |
          | 适用场景 | 正式的事件处理（遵循 .NET 事件模型）	   | 通用的无返回值方法引用（如回调、简单事件） |
          | 是否包含事件源 | 包含（sender 参数） | 不包含（需手动传递，若需要） |
                             
    * Func<T> 是 C# 内置的有返回值的泛型委托（位于 System 命名空间），语法为：
        Func<TResult>：无参数，返回值类型为 TResult
        Func<T1, TResult>：1 个参数（T1 类型），返回值 TResult
        Func<T1, T2, TResult>：2 个参数，返回值 TResult
        基于Func<T>声明事件：// 声明有返回值的事件（基于 Func，返回值为 int）
                            // 签名：(object sender, CalculateEventArgs e) => int
                            public event Func<object, CalculateEventArgs, int> OnCalculate;

* 事件池
  * 引用池
  * 对象池 
    * https://www.cnblogs.com/mezero/p/3955130.html
    * http://www.xuanyusong.com/archives/2974

* 泛型类型约束
  * 泛型可以在编译时检查类型，避免运行时的类型转换错误。
  * <T> 本质是一个 “类型占位符”，让类 / 接口 / 方法可以在不指定具体类型的情况下定义通用逻辑，使用时再根据需要传入具体类型（如   IFsm<Player>、Fsm<Enemy>）
  * C# 的泛型语法强制要求：泛型方法必须在方法名后用 <> 声明泛型参数。public void Fun<TEvent>(Action<TEvent> action),如果方法名 Fun 后没有 <TEvent>，编译器会把 TEvent 当成一个 “已定义的具体类型”，此时会报 “找不到类型或命名空间 TEvent” 的错误。
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