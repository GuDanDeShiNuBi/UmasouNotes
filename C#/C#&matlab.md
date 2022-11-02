- [matlab安装教程](https://blog.csdn.net/GGY1102/article/details/121733746)
- [matlab教程](https://www.w3cschool.cn/matlab/matlab-e61o28ge.html)
  
- [matlab&&c#混合编程](https://blog.csdn.net/liu16659/article/details/52442435)
  - [2](https://blog.csdn.net/yty2545340913/article/details/123127784)
  - [3](https://blog.csdn.net/weixin_40405758/article/details/81940071)
  - [4](https://blog.csdn.net/qq_45689779/article/details/121699015)
- [C#函数利用COM自动控制接口](https://blog.csdn.net/qq_36320710/article/details/107114811)
  - [添加mlapp引用](https://www.cnblogs.com/Miliery/articles/4443783.html)
- [C#调用matlab时的类型初始值设定项引发异常](https://blog.csdn.net/wjyboomshakalaka/article/details/81737453)
- [c#调用matlab画图](https://blog.csdn.net/yxy244/article/details/79305757)
- [matlab打包成dll供.net使用出现错误](https://bbs.csdn.net/topics/392564943)

- [matlab与c#数据传递](https://blog.csdn.net/u012440550/article/details/43297979)   
  - [数据转换](https://blog.csdn.net/zwjabcd/article/details/50663149)
  - [C#使用Math.NET读取mat文件](https://blog.csdn.net/kenjianqi1647/article/details/89487220)
  - [复数数据从c#客户端传递给matlab](https://ww2.mathworks.cn/help/matlab/matlab_external/call-matlab-function-from-a-c-client.html)
  - [c#与simulink交互数据](https://blog.csdn.net/maybe987/article/details/115892260)
  - [Simulink模型与C#界面实时仿真](https://www.ilovematlab.cn/thread-277804-1-1.html)


### region 

- C#结合Matlab函数有两种形式
  - 1、将Matlab .m文件放置VS项目文件Debug下，通过MLApp读取。目前无变量的程序测试通过，氢能程序程序测试未通过
  - 2、将matlab函数制成DLl文件，VS添加引用进行调用。无方法体的函数无法做成dll,不是.m的文件无法做成dll
  - 两种方法发布的应用，运行电脑没有mablab运行环境均不能打开matlab figure图表。第一种方法，目标电脑没有matlab运行环境，函数与图表均不能响应
  - matlab中涉及到simulink的程序无法调用