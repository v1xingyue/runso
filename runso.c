// 生成调用so 的实例
// make

#include <stdio.h>
#include <dlfcn.h>

typedef int (*SoHandler)();

int main(){
    printf("# runso tools #\n");
    void *so_handle=dlopen("./item/goso.so",RTLD_LAZY);
    SoHandler sh = NULL;
    sh = dlsym(so_handle,"RunSo");
    sh();
    printf("\n");
    return 0;
}
