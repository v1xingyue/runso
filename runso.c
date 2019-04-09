// 生成调用so 的实例
// make
// cd item ; make
// ./runso -d ./item/ -s goso -f RunSo 

#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>

struct _RunSoArgs {
    char* soname;
    char* sopath;
    char* fname;
    int multiple;
} RunArgs;

typedef int (*SoHandler)();

void RunSoFn(char *so_path,char* soname,char* fn_name){
    char buffer[256];
    sprintf(buffer,"%s/%s.so",so_path,soname);
    printf("   call %s from sopath: %s , so full path : %s , soname : %s\n",fn_name,so_path,buffer,soname);
    void *so_handle=dlopen("./item/goso.so",RTLD_LAZY);
    SoHandler sh = NULL;
    sh = dlsym(so_handle,fn_name);
    if(sh == NULL){
        printf("no method found !\n");
    } else {
        sh(); 
    }
}

void usage(){
    printf("\n");
    printf("");
    printf("# RunSo tools #\n");
    printf("-n soname , without .so suffix \n");
    printf("-d so path , with right / \n");
    printf("-c function name to call default : RunSo . This Export Function Must be int (*SoHandler)()  \n");
    printf("-m call multiple so files , loop so dir \n");
    printf("example usage:  ./runso -d ./item -n goso -c RunSo\n");
    printf("\n");
}

int main(int argc, char** argv){

    char ch;
    RunArgs.multiple = 0;

    while((ch = getopt(argc, argv, "n:d:c:mh")) != -1){
        switch(ch) {
            case 'n':
                //printf("option s:'%s'\n", optarg);  
                RunArgs.soname = optarg;
                break;
            case 'd':
                //printf("option d: %s \n",optarg);  
                RunArgs.sopath = optarg;
                break;
            case 'c':
                //printf("option f: %s \n",optarg);  
                RunArgs.fname = optarg;
                break;
            case 'm':
                //printf("with option m: \n");  
                RunArgs.multiple = 1;
                break;
            default:
                usage();
                return 1;
        }
    }

    if(RunArgs.soname == NULL || RunArgs.sopath == NULL){
        usage();
        return 1; 
    }

    if(RunArgs.fname == NULL){
        RunArgs.fname = "RunSo"; 
    }

    if(RunArgs.multiple == 0){
        RunSoFn(RunArgs.sopath,RunArgs.soname,RunArgs.fname);
    } else {
    
    }

    printf("\n");
    return 0;
}

