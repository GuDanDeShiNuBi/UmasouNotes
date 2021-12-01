*   实用优化
    *   使用unity profiler工具，针对性的对性能瓶颈优化
    *   判断物体是否在摄像机照射范围内
        *   MeshRender.isVisible;
    *   程序替换材质和贴图
        *   换贴图比换材质性能消耗更低
    *   控制帧率。不要直接使用VSyncCount控制帧率了。否则在120hz刷新率的手机上vSyncCount=1会有120fps的帧率。直接使用targetFrameRate=30来设置帧率。
    *   drawcall优化
        *   [DrawCall优化](https://blog.csdn.net/qq_14939027/article/details/54708264?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-0.control&spm=1001.2101.3001.4242)
        *   介绍
            *   DrawCall : CPU发送渲染命令给GPU
            *   一个mesh一个drawcall
            *   一个material一个drawcall
    *   Gameobject.Setactive
        *   当一个物体被显示隐藏是会在每次使用的时候遍历这个实体上所有继承MonoBehaviour的脚本,调用OnEnable和OnDisable 方法
        *   [SetActive 优化](https://blog.csdn.net/u014746275/article/details/88363275)