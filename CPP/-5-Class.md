### *__类__*

___

_类的基本思想是数据抽象和封装。数据抽象是一种依赖于接口和实现分离的编程技术。类的接口包括用户所能执行的操作；类的实现则包括类的数据成员、负责接口实现的的函数体与及定义类所需的各种私有函数。封装实现了类的接口和实现的分离。封装后的类隐藏了它的实现细节。_

* 定义抽象数据类型
  * 通常建议将类定义写在头文件中，而将实现放在源文件中，以便其他源文件可以包含头文件并使用该类。具体来说，实现可以写在.cpp文件中，类声明可以写在.h文件中
  * 成员函数的声明必须在类的内部，它的定义可以在类的内部也可以在类的外部。作为接口组成部分的非成员函数，它们的定义和声明都在类的外部。
    ``` 
    struct Sales_data
    {
        std::string isbn()const { return bookNo; } //成员函数isbn定义在了类内
        Sales_data& combine(const Sales_data&);  //定义在了类外
        double avg_price()const;      //定义在了类外

        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0;
    };
    //Sales_data的非成员接口函数
    Sales_data add(const Sales_data&, const Sales_data);
    std::ostream &print(std::ostream&, const Sales_data&);
    std::istream &read(std::istream&, Sales_data&);
    ```
  * this
    * 当调用一个成员函数时，用请求该函数的对象地址初始化this
    * this是一个常量指针
    * this属于该成员函数的隐式形参
    * 当外部执行total.isbn()时，编译器负责把total的地址传递给成员函数isbn的引用形参this，如以下形式：Sales_data:isbn(&total)。函数的this形参是隐式定义的
  * const成员函数
    * 默认情况下，this的类型是指向类类型非常量版本的常量指针。上述代码Sales_data成员函数中，this类型是Sales_data*const。此时的this不能绑定到常量对象上
    * isbn函数后紧跟了一个const关键字，作用是修改隐式this指针的类型，表示this是一个指向常量的指针
    * 伪代码：std::string Sales_data::isbn(const Sales_data *const this)
    * 常量对象、常量对象的引用或指针都只能调用常量成员函数
  * bookNo定义在isbn()之后，却可以使用该成员，因为编译器首先编译成员的声明，然后轮到成员函数体
  * 在类的外部定义成员函数
    * 返回类型、参数列表、函数名、const属性必须保持一致，同时成员的名字必须包含它所属的类名
      * > double Sales_data::avg_price()const{/*...*/}; //::属于作用域运算符，说明该函数被声明在Sales_data的作用域内
  * 定义一个返回this对象的函数
    ``` 
    Sales_data& Sales_data::combine(const Sales_data &rhs)//函数调用者为this，也为Sales_data类型
     {
      units_sold+=rhs.units_sold;
      revenue+=rhs.revenue;
      return *this;
     } 
     ```
  * 定义类相关的非成员函数
    * 非成员函数的声明与定义其他函数一样，通常把函数的声明和定义分离开来
    * 一般来说，如果非成员函数是类接口组成部分，则这些函数的声明应该与类在同一个头文件内
    ```
    istream &read(std::istream &is, Sales_data &item) 
    {
      double price=0;
      is>> item.bookNo>>item.units_solds>>price;
      item.revenus=price*item.unit_solds;
      return is;
    }
    ```
    * IO类属于不能被拷贝的类型，只能通过引用传递
  * 构造函数 
    * 初始化类对象的数据成员，只要类对象被创建，就会执行构造函数
    * 构造函数名字与类名相同
    * 构造函数没有返回类型
    * 有一个可能为空的参数列表和一个可能为空的函数体
    * 类可以包含多个构造函数，必须在参数数量或参数类型上有所区别
    * 构造函数不能被声明成const
    * 只有类没有声明任何构造函数时，编译器才会自动地生成默认构造函数，所以当我们定义了其他构造函数，那么也必须定义一个默认构造函数
    * 如果类包含内置类型或复合类型的成员，只有当这些成员全都被赋予了类内的初始值时，这个类才适合于使用合成的默认构造函数，否则将出现未定义问题
    * 类的内部定义构造函数
      * Sales_data()=default;//定义默认构造函数
      * Sales_data(const std::string &s): bookNo(s){}
        * 冒号与花括号之间的代码，为构造函数初始值列表，用来为数据成员赋初值。当某个成员被构造函数初始值列表忽略时，它将与合成默认构造函数相同的方式隐式初始化。可使用类内初始值初始化
    * 类的外部定义构造函数
      * 以istream为参数的构造函数,需要执行一些实际操作
      ```
      Sales_data::Sales_data(std::istream &is){
        read(is,*this);
      }
      ```
      * 首先指明类
      * 没有构造函数初始值列表
     
___

* 访问控制和封装
  * 访问说明符
    * 定义在public说明符之后的成员在整个程序内可被访问，public成员定义类的接口
    * 定义在private说明符之后的成员可以被类的成员函数访问，但不能被使用该类的代码访问
  * class与struct关键字
    * struct,定义在第一个访问说明符之前的成员是public
    * class ,成员是private
    * 区别就是默认的访问权限不同
    * 当希望定义的类的所有成员是public时，使用struct，反之，如果希望成员是private的，使用class
  
  * 友元
    * 类可以运行其他类或函数访问它的友元，方法是令其他类或者函数成为它的友元。函数声明语句前增加friend关键字
    * 友元的声明仅仅指定了访问的权限。需要在友元声明之外专门对函数进行一次声明。
    * 通常把友元的声明与类本身放置在同一个头文件内

    ```
    class Sales_data
    {
      friend Sales_data add(const Sales_data&, const Sales_data);
      friend std::ostream &print(std::ostream&, const Sales_data&);
      friend std::istream &read(std::istream&, Sales_data&);

    public:
      Sales_data() = default;
      Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
      Sales_data(const std::string &s):bookNo(s){}
      std::string isbn()const { return bookNo; }
      Sales_data& combine(const Sales_data&);

    private:

      double avg_price()const { return units_sold ? revenue / units_sold : 0; }
      std::string bookNo;
      unsigned units_sold = 0;
      double revenue = 0;
    };

    Sales_data add(const Sales_data&, const Sales_data);
    std::ostream &print(std::ostream&, const Sales_data&);
    std::istream &read(std::istream&, Sales_data&);
    ```
___

* 类的其他特性
  * 类成员
    - 定义一个类型成员
      - 除了定义数据和函数之外，类还可以自定义某种类型在类中的别名 
    - 令成员作为内联函数
    - 可变数据成员
      - 即使在一个const成员函数内，也能修改类的某个数据成员。
      - 在变量的声明中加入mutable关键字
  * 返回*this的成员函数 
    - 一个const成员函数如果以引用的形式返回*this,那么它的返回类型将是常量引用（成员函数可以通过关键字 const 来修饰，表示该成员函数不会修改对象的状态。当一个成员函数被声明为 const 时，它不能修改对象的成员变量，并且只能调用其他 const 成员函数或者访问对象的 const 成员。当 const 成员函数以引用的形式返回 *this，即返回对象自身的引用，编译器将自动为返回类型添加常量修饰，从而得到常量引用类型。这是为了防止通过这个引用修改对象的成员变量，保证了对象的状态在调用 const 成员函数后仍然保持不变。）
    - 基于const的重载
      - 非常量版本的函数对于常量对象是不可用的，只能在一个常量对象上调用const成员函数。可以在非常量对象上调用常量版本或非常量版本
    ``` 
         Screen.h    
          class Screen
          {
          public:
            typedef std::string::size_type pos;
            Screen() = default;
            Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
            char get()const { return contents[cursor]; }  //隐式内联
            inline char get(pos ht, pos wd)const; //类内部显示内联
            Screen &move(pos r, pos c);
            void some_member()const;
            Screen &set(char);
            Screen &set(pos, pos, char);
            //根据对象是否是const重载了display函数
            Screen &display(std::ostream &os) { do_display(os); return *this; }
            const Screen &display(std::ostream &os) const { do_display(os); return *this; }

          private:
            pos cursor = 0;
            pos height = 0, width = 0;
            std::string contents;
            mutable rsize_t access_ctr;//即使在一个const对象内也能被修改
            void do_display(std::ostream &os)const { os << contents; }

          }; 
         Screen.cpp
          char Screen::get(pos r, pos c) const
            {
              pos row = r * width;

              return contents[row+c];
            }

            inline   //类外部内联
            Screen & Screen::move(pos r, pos c)
            {
              pos row = r * width;
              cursor = row + c;
              return *this;

            }

            void Screen::some_member() const
            {
              ++access_ctr;
            } 
            Screen & Screen::set(char c)
            {
              contents[cursor] = c; //设置当前光标所在位置的新值
              return *this; //将this对象作为左值返回
            }

            inline Screen & Screen::set(pos r, pos col, char ch)
            {
              contents[r*width + col] = ch;//设置给定位置的新值
              return *this; //将this对象作为左值返回
            }
    ```
  * 类之间的友元关系
    * 如果一个类指定了友元类，则友元类的成员函数可以访问此类包括非公有成员在内的所有成员
    * 令成员函数作为友元时，需明确指出该成员函数所属哪个类
    

___

* 类的作用域
  * 编译器处理完类中的全部声明后才会处理成员函数的定义
  * 成员函数中使用的名字解析流程：
    * 首先 ，在成员函数内查找该名字的声明。只有在函数使用之前出现的声明才被考虑
    * 如果在成员函数内没有找到，则在类内继续查找，这是类的所有成员都可以被考虑
    * 如果类内也没找到该名字的声明，在成员函数定义之前的作用域内继续查找  


___

* 构造函数再探
  * 构造函数初始化列表
    * 如果成员是const或引用，必须将其初始化
    * 如果成员是const或引用或属于某种为提供默认构造函数的类类型，必须通过构造函数初始值列表为这些成员提供初值
    * 建议使用构造函数初始值。初始化与赋值的区别事关底层效率问题：前者直接初始化数据成员，后者则先初始化再赋值
    * 成员的初始化顺序与它们在类定义中的出现顺序一致：第一个成员先被初始化，然后第二个，以此类推。
    * 如果一个构造函数为所有参数都提供了默认实参，则它实际上也定义了默认构造函数
  * 委托构造函数
    * 一个委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程
    * 委托构造函数也有一个成员初始值列表和一个函数体。成员初始值列表只有一个唯一的入口，就是类名本身
    * > Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
    * > Sales_data():Sales_data("",0,0){};//委托构造函数
    * > Sales_data(std::string s):Sales_data(s,0,0){};//委托构造函数
  * 隐式的类类型转换
    * 能通过一个实参调用的构造函数定义了一条从构造函数的参数类型向类类型隐式转换的规则
    * 编译器只会自动地执行一步类型转换，但可以改为显式的转换
      * >item.combine("00-999-99");//错误，需要先转成string ,再转为类类型
      * > item.combine(string("00-999-99"));//正确，先显示的转换为string,再隐式转换为sales_data
      * > item.combine(Sales_data("00-999-99"));//正确，先显示的转换为再隐式转换为sales_data,再隐式转换为string
    * 抑制构造函数定义的隐式转换
      * 将构造函数声明为explicit
      * 该关键字只对一个实参的构造函数有效，且只能在类内的构造函数使用
      * explicit构造函数只能用于直接初始化，不能使用拷贝形式的初始化
    * 可以为转换显示的使用构造函数
      * 编译器不会将explicit的构造函数用于隐式转换过程，但是可以强制的显示转换
      * 标准库中含有显式构造函数的类
        * 接受一个单参数的cosnt char *的string构造函数，不是explicit的
        * 接受一个容量参数的vector构造函数，是explicit的 

___

* 类的静态成员
  * 声明静态成员
    * 静态成员可以是public或private
    * 可以是常量、引用、指针、类类型等。
    * 类的静态成员存在与任何对象之外，对象中不包含任何与静态成员有关的数据 
  * 使用类的静态成员
    * 使用作用域运算符直接访问
      * classX::staticFunc();
    * 使用类的对象、引用、指针来访问静态成员
    * 成员函数不用通过作用域运算符就能直接使用静态成员
  * 定义静态成员
    * 当在类的外部定义静态成员时，不能重复static关键字，该关键字只出现在类内部的声明语句
    * 静态成员不是由类的构造函数初始化的，必须在类的外部定义和初始化每个静态成员
    * 定义静态成员：对象的类型名+类名+作用域运算符+成员自己的名字
  * 静态成员的类内初始化
    * 静态成员必须是字面值常量类型的constexpr，初始值必须是常量表达式
  * 静态成员与普通成员
    * 静态数据成员可以是不完全类型，数据成员必须是完全类型
    * 可以使用静态成员作为默认实参，非静态成员不能作为默认实参，因为它的值本身属于对象的一部分