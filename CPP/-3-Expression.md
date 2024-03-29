
### *__表达式__*

___

* 左值与右值
  * 左值指的是可以被取地址的表达式，也就是说左值可以出现在赋值语句的左侧，而右值则是指不能被取地址的表达式
  ``` 
    int a = 10; // ‘a’是一个左值，因为它具有可寻址性（addressable）
    int b = a; // ‘a’是一个左值，因为它可以出现在等号左侧；‘b’也是一个左值，因为它也具有可寻址性
   ```
* 优先级与结合律
  * 同一优先级按照从左向右的顺序运算

* 算数运算符
  * 布尔值不应该参与计算，布尔类型的运算对象被提升为int类型，如果b的值为真，则在运算时被提升为整数1，对其求负，结果为-1，该值不等于0，再转为布尔值为1，还为真。
    * > bool b=true;
    * > bool b2=-b;  //此时b2还是true;
  * 算数表达式可能产生溢出，例如short类型为16位，溢出后的结果为负数,说明该值发生了环绕，符号位本来为0，由于溢出变为了1；
  * 运算符%为取余或取模运算符，负责计算两个整数相除所得的余数，且运算对象必须为整数类型

* 逻辑与关系运算符
  * > if(val)  //如果val是任意的非0值，条件为真
  * > if(!val)  //如果val等于0，条件为真

* 赋值运算符
  * 赋值运算满足右结合律
  * 赋值运算符的优先级低于关系运算符，所以在条件语句中，赋值部分应该加上括号
  * 复合赋值运算符
    * += -= <<= >>= ...
    * 任意一种复合运算符都等价于 a=a op b;

* 递增递减运算符
  * > int i=0,j;
  * > j=++i;   //  j=1,i=1;前置版本得到递增之后的值
  * > j=i++;   // j=1,i=2;后置版本得到递增之前的值
  * 这两种运算符必须作用于左值运算对象，前置版本将对象本身作为左值返回，后置版本则将对象原始值的副本作为右值返回，非必要不使用后置

* 成员访问运算符
  * 点运算符与箭头运算符
    * ptr ->mem等价于 （*ptr）.mem  
    * 解引用运算符的优先级低于点运算符，所以需要加括号

* 条件运算符
  * _cond?expr1:expr2_
  * 条件运算符的优先级很低，需要加括号

* 位运算符
  * 位运算符作用于整数类型的运算对象，并把运算对象看成是二进制位的集合。位运算符提供检查和设置二进制位的功能。
  * 标准库bitset类型也可以表示二进制位集合
  * > '<<' 左移
  * > '>>' 右移
  * > '~' 位求反运算符
  
* 类型转换
  * 隐式类型转换
    * 在大多数表达式中，比int类型小的整型值首先提升为较大的整数类型
    * 在条件中，非布尔值转换成布尔类型
    * 初始化过程中，初始值转换成变量的类型
    * 如果算数运算或关系运算的运算对象有多种类型，需要转换成同一种
  * 整型提升：负责将小整数类型转换成较大的整数类型。对于bool、char、signed char、unsigned char、short、unsigned short等类型，只要它们所有可能的值能存在int里，它们就会提升为int类型，否则提升成unsigned int类型。
    * int类型与unsigned int 类型
      * int 类型可以表示负数和非负数，而 unsigned int 只能表示非负数
      * signed int 类型的取值范围为 -2^(n-1) ~ 2^(n-1)-1，其中 n 是该类型所占的比特数。unsigned int 类型的取值范围为 0 ~ 2^n-1，其中 n 是该类型所占的比特数。
  * 显式类型转换
  * - static_cast：用于基本类型和用户定义类型之间的转换。
    - reinterpret_cast：用于类型之间的二进制转换。
    - const_cast：用于改变常量或者非常量类型的 const 或 volatile 限定符。
    - dynamic_cast：用于在面向对象编程中转换类类型的指针或引用。
