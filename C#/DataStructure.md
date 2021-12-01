*   数据结构
    *   Array(数组)
        *   概述           
            *   数组可以直接通过下标访问。               
            *   数组存储在连续的内存上。
            *   数组的内容都是相同类型。
        *   原理
            *   *   ![](https://api2.mubu.com/v3/document_image/10e4b64b-c3d2-41bf-9e94-eee3430ec114-11312918.jpg)
            *   创建一个新的数组时将在 CLR 托管堆中分配一块连续的内存空间，来盛放数量为size，类型为所声明类型的数组元素。
        *   声明
            *   double\[\] balance = new double\[10\];balance\[0\] = 4500.0;
            *   double\[\] balance = { 20.0, 43.69, 31.0};
            *   int \[\] marks = new int\[\] { 99, 98, 92, 97, 95};
        *   初始化
            *   声明了数组之后，就必须为数组分配内存，以保存数组的所有元素。数组是引用类型，所以必须给它分配堆上的内存。为此，应使用new运算符，指定数组中元素的类型和数量来初始化数组的变量。
            *   *   ![](https://api2.mubu.com/v3/document_image/e72522f3-7115-4d36-bab1-258e64a1a3e7-11312918.jpg)
        *   优点
            *   由于是在连续内存上存储的，所以它的索引速度非常快，访问一个元素的时间是恒定的也就是说与数组的元素数量无关，而且赋值与修改元素也很简单。
        *   缺点
            *   由于是连续存储，所以在两个元素之间插入新的元素就变得不方便。而且就像上面的代码所显示的那样，声明一个新的数组时，必须指定其长度，这就会存在一个潜在的问题，那就是当我们声明的长度过长时，显然会浪费内存，当我们声明长度过短的时候，则面临这溢出的风险。
        
    *   ArrayList(动态数组)
        *   概述
            *   为了解决数组创建时必须指定长度以及只能存放相同类型的缺点而推出的数据结构。
        *   声明
            *   ArrayList是System.Collections命名空间下的一部分，所以若要使用则必须引入System.Collections。
            *   ArrayList test = new ArrayList();
        *   优点
            *   不必在声明ArrayList时指定它的长度，这是由于ArrayList对象的长度是按照其中存储的数据来动态增长与缩减的。
            *   ArrayList可以存储不同类型的元素。这是由于ArrayList会把它的元素都当做Object来处理。
        *   缺点
            *   ArrayList不是类型安全的。因为把不同的类型都当做Object来做处理，很有可能会在使用ArrayList时发生类型不匹配的情况。
            *   ArrayList由于把所有类型都当做了Object，所以不可避免的当插入值类型时会发生装箱操作，在索引取值时会发生拆箱操作。
        
    *   List<T>(泛型集合)
        *   概述
            *   为了解决ArrayList不安全类型与装箱拆箱的缺点，所以出现了泛型的概念，作为一种新的数组类型引入。也是工作中经常用到的数组类型。和ArrayList很相似，长度都可以灵活的改变，最大的不同在于在声明List集合时，我们同时需要为其声明List集合内数据的对象类型，这点又和Array很相似，其实List<T>内部使用了Array来实现。
        *   优点
            *   确保了类型安全。
            *   取消了装箱和拆箱的操作。
            *   它融合了Array可以快速访问的优点以及ArrayList长度可以灵活变化的优点。
        *   源码
            *   [https://referencesource.microsoft.com/#mscorlib/system/collections/generic/list.cs,9808f1f5ef16c436](https://referencesource.microsoft.com/#mscorlib/system/collections/generic/list.cs,9808f1f5ef16c436)
            *   [https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1?view=net-5.0](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.list-1?view=net-5.0)
        
    *   LinkedList<T>(链表)
        *   概述
            *   链表在内存存储的排序上可能是不连续的。这是由于链表是通过上一个元素指向下一个元素来排列的，所以可能不能通过下标来访问。
            *   *   ![](https://api2.mubu.com/v3/document_image/ae10f6c1-3b87-4946-8be3-5cba0b5f1388-11312918.jpg)
            *   LinkedList<T>集合类没有非泛型类的版本，它是一个双向链表，它的元素指向元素的前一个与后一个元素
        *   优点
            *   向链表中插入或删除节点无需调整结构的容量。因为本身不是连续存储而是靠各对象的指针所决定，所以添加元素和删除元素都要比数组要有优势。
            *   链表适合在需要有序的排序的情境下增加新的元素，这里还拿数组做对比，例如要在数组中间某个位置增加新的元素，则可能需要移动移动很多元素，而对于链表而言可能只是若干元素的指向发生变化而已。
        *   缺点
            *   由于其在内存空间中不一定是连续排列，所以访问时候无法利用下标，而是必须从头结点开始，逐次遍历下一个节点直到寻找到目标。所以当需要快速访问对象时，数组无疑更有优势。
            *   链表适合元素数量不固定，需要经常增减节点的情况
        *   注解
            *   [https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.linkedlist-1?redirectedfrom=MSDN&view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.linkedlist-1?redirectedfrom=MSDN&view=netframework-4.8)
        
    *   Queue<T>(队列)
        *   概述
            *   在Queue<T>这种数据结构中，最先插入在元素将是最先被删除；反之最后插入的元素将最后被删除，因此队列又称为“先进先出”（FIFO—first in first out）的线性表。
            *   *   ![](https://api2.mubu.com/v3/document_image/fd42e81b-227c-40f2-bcb4-94632ed35712-11312918.jpg)
        *   详解
            *   通过使用Enqueue和Dequeue这两个方法来实现对 Queue<T> 的存取。
            *   默认情况下，Queue<T>的初始容量为32， 增长因子为2.0。
            *   当使用Enqueue时，会判断队列的长度是否足够，若不足，则依据增长因子来增加容量，例如当为初始的2.0时，则队列容量增长2倍。
        
    *   Stack<T>（堆栈）
        *   概述
            *   使用后进先出顺序（LIFO）的数据结构
            *   元素从栈的尾部插入，从栈的尾部移除，类似于日常生活中搬家的时候装车，先装上车的东西要后拿下来。
        *   详解
            *   使用pop和push来操作
            *   默认容量为10
            *   [https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1?redirectedfrom=MSDN&view=netframework-4.8](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.stack-1?redirectedfrom=MSDN&view=netframework-4.8)
                
    *   Dictionary<K,T>（字典）
        *   概述
            *   提到字典就不得不说Hashtable哈希表以及Hashing（哈希，也有叫散列的），因为字典的实现方式就是哈希表的实现方式。
            *   在创建字典时，我们可以传入一个容量值，但实际使用的容量并非该值。而是使用“不小于该值的最小质数来作为它使用的实际容量，最小是3。”，当有了实际容量之后，并非直接实现索引，而是通过创建额外的2个数组来实现间接的索引，即int\[\] buckets和Entry\[\] entries两个数组（即buckets中保存的其实是entries数组的下标），这里就是第二条字典与哈希表的区别，还记得哈希冲突吗？对，第二个区别就是处理哈希冲突的策略是不同的！字典会采用额外的数据结构来处理哈希冲突，这就是刚才提到的数组之一buckets桶了，buckets的长度就是字典的真实长度，因为buckets就是字典每个位置的映射，然后buckets中的每个元素都是一个链表，用来存储相同哈希的元素，然后再分配存储空间。
            *   *   ![](https://api2.mubu.com/v3/document_image/95ce3162-e6d6-48f2-a8d3-d5a007549ca1-11312918.jpg)
        *   优点
            *   字典是类型安全的，也就是说当创建字典时，必须声明key和item的类型，这是第一条字典与哈希表的区别。
        *   缺点
            *   以空间换时间，通过更多的内存开销来满足我们对速度的追求。
        
    *   小结（适用）
        *   Array
            *   需要处理的元素数量确定并且需要使用下标时可以考虑，不过建议使用List<T>
            
        *   ArrayList
            *   不推荐使用，建议用List<T>
                
        *   List<T>泛型List
            *   需要处理的元素数量不确定时 通常建议使用
            
        *   LinkedList<T> 链表
            *   适合元素数量不固定，需要经常增减节点的情况，2端都可以增减
                
        *   Queue<T>
            *   先进先出的情况
                
        *   Stack<T>
            *   后进先出的情况
                
        *   Dictionary<K,T>
            *   需要键值对，快速操作