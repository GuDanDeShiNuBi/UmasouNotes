*   LearnCPlusPlus
    *   学习网站
        *   [最好的C++教程\_哔哩哔哩\_bilibili](https://www.bilibili.com/video/BV1VJ411M7WR)
        *   [The C++ Tutorial | Learn C++ (learncpp.com)](https://www.learncpp.com/)
*   笔记
    *   预处理指令（preprocessor）
        *   #include<iostream>
            *   编译文件之前进行评估，将iostream内容拷贝进来
    *   main函数
        *   只有main函数不用返回值，默认返回0
    *   cin.get()
        *   输入回车才会执行下面一行代码
    *   每个cpp文件被编译成一个object文件，扩展名windows使用.obj
    *   cpp源文件-obj-链接器-exe
    *   declaration(声明)&&definition(定义)
    *   compiler
        *   proprocessor(头文件)-cpp-translation unit-obj
    *   指针（pointers）
        *   是一个整数，存储着一个内存地址
        *   &var
            *   获取变量的内存地址，赋给指针
                *   void\*ptr=&var
        *   指针的指针
            *   char\[\]buffer=new char\[8\]
            *   memset(buffer,0,8)
            *   char\*\*ptr=&buffer
            *   \*ptr最终指向00,00,00,00
    *   引用（reference）
        *   紧贴变量类型为引用
            *   Int&、float&
        *   &a
            *   代表a的内存地址
        *   不是真正的变量，相当于变量的另外一个名称
        *   \*var
            *   代表解引用，指的是内存地址所指向的值
    *   对象与实例化
        *   由类类型制成的变量叫做对象，新创建对象的过程叫做实例化
    *   类与结构体（class&structure）
        *   class默认情况下是私有的，struct是公有的
        *   结构体通常用于代替一个结构中的一些数据
    *   static
        *   当你定义一个静态函数或者变量，只对它声明所在的cpp文件“可见”
        *   静态方法不能访问非静态变量，静态方法没有类实例
    *   变量
        *   声明一个变量时，要考虑到变量的生存期和作用域
        *   局部静态变量（local static）
            *   在函数内声明，函数被首次调用时被声明，只执行一次，相当于函数外的方法，但只在函数内可见