*   点乘、叉乘
    *   [向量运算（点乘和叉乘）](https://zhuanlan.zhihu.com/p/89046275)
    *   两个向量点乘得到一个投影
        *  根据值来判断在前方或者后方
    *   两个向量叉乘得到一个法向量
        * 判断物体在左在右
*   确定一个平面
    *   确定一个plane
        *   //平面内一个+平面法向量
            *   public Plane(Vector3 inNormal, Vector3 inPoint);
        *   //平面法向量+长度
            *   public Plane(Vector3 inNormal, float d);
        *   //平面内任意不共线的三个点
            *   public Plane(Vector3 a, Vector3 b, Vector3 c);
        *   [blog](https://blog.csdn.net/m0_37763682/article/details/106367753)