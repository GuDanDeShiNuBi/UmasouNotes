
### *__IO库__*

__ _


* IO库设施：
  * istream（输入流）类型，提供输入操作
  * ostream (输出流) 类型。提供输出操作
  * cin,一个istream对象，从标准输入读取数据
  * cout，一个ostream对象，向标准输出写入数据
  * cerr,一个istream对象，通常用于输出程序错误消息，写入标准错误
  * ‘>>’运算符，用来从一个istream对象读取输入数据
  * ‘<<’运算符，用来像一个ostream对象写入输出数据
  * getline函数，从一个给定的istream读取一行数据，存入一个给定的string对象

___

* IO库类型
  * 头文件                 类型
  * iostream(流)      istream(从流读取数据)，ostream(向流写入数据)，iostream(读写流)
  * fstream（文件）    ifstream，ofstream，fstream
  * sstream(string)   istringstream,ostringstream,stringstream
  * 类型iftream和istringstream继承自istream,使用方法与istream一样，ofstream和ostringstream继承自ostream
  * IO对象无拷贝或赋值，所以进行IO操作的函数通常以引用方式传递和返回流。读写一个IO对象会改变其状态，因为传递和返回引用不能是const
  * IO条件状态
    * strm::iostate  // iostate提供了表达条件状态的完整功能
    * strm::badbit   //用来指出流已崩溃
    * strm::failbit  //用来指出IO操作失败
    * strm::eofbit   //用来指出流到达了文件结束
    * strm::goodbit  //用来指出流未处于错误状态

___

* fstream :文件输入输出
  * fstream特有的操作
    * fstream fstrm  //创建一个未绑定的文件流
    * fstream fstrm（s）  //创建一个fstream,并打开名为s的文件
    * fstream fstrm（s,mode）  //同时，但按指定mode打开文件
    * fstrm.open(s)  //打开名为s的文件，并将文件与fstrm绑定
    * fstrm.close()  //关闭与fstrm绑定的文件
    * fstrm.is_open() //返回一个bool值
  * 使用文件流对象
    * 创建文件流对象时，可以提供文件名，此时open会自动被调用
    * ifstream in(ifile);//定义了一个输入流in。它被初始化为从文件读取数据
    * ofstream out
    * 当一个fstream对象被销毁时，close会自动被调用
  * 文件模式
    * 每个流都有一个关联的文件模式，用来指出如何使用文件
      * in  以读方式打开（只能对ifstream或fstream对象设定）
      * out  以写方式打开（只能对ofstream或fstream对象设定）
      * app  每次写操作前均定位到文件末尾（默认情况下，没有指定trunc，以out模式打开的文件也会被截断。为了保留文件内容，必须同时指定app模式，这样只会将数据追加写到文件末尾；或者指定in模式，即打开文件同时进行读写操作）
      * ate  打开文件后立即定位到文件末尾
      * trunc 截断文件(只有当out也被设定时，才可设定此模式)
      * binary 以二进制方式进行IO
       
___

* stringstream: string流
  * stringstream特有的操作
    * sstream strm
    * sstream strm(s)
    * strm.str()  //返回strm所保存的string的拷贝
    * strm.str(s) //将string s 拷贝到strm中。
  * 使用
    ```
    struct PersonInfo
    {
      string name;
      vector<string>phones;
    };
    string line, word;
    vector<PersonInfo>people;
    while (getline(cin,line))
    {
      PersonInfo info;
      istringstream record(line);//将记录绑定到刚读入的行
      record >> info.name;//读取名字
      while (record>>word)//读取电话号码
      {
        info.phones.push_back(word);
      }
      people.push_back(info);
    } 
    ```
