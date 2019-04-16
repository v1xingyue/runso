#ifndef ____RUN_SO_TYPE_H
#define ____RUN_SO_TYPE_H

#ifndef buildnum
#define buildnum ""
#endif

// 运行参数定义
struct _RunSoArgs {
    char* soname;
    char* sopath;
    char* fname;
    int multiple;
};

// so 动态调用函数指针类型
typedef int (*SoHandler)();

// so 回调函数
typedef void (*CallBack)();

#endif
