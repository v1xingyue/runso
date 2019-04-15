#ifndef ____RUN_SO_H
#define ____RUN_SO_H

#ifndef buildnum
#define buildnum ""
#endif

// 运行参数定义
struct _RunSoArgs {
    char* soname;
    char* sopath;
    char* fname;
    int multiple;
} RunArgs;

// so 动态调用函数指针类型
typedef int (*SoHandler)();

#endif
