// 生成调用so 的实例
// make
// cd item ; make
// ./runso -d ./item/ -s goso -f RunSo 

#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

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


// 动态调用指定目录下的so文件的指定函数，该导出函数，比如符合 SoHandler 类型定义
void RunSoFn(char *so_path,char* soname,char* fn_name){
    char buffer[256];
    sprintf(buffer,"%s/%s.so",so_path,soname);
    printf(" \033[0;32m   call %s from sopath: %s , so full path : %s , soname : %s \033[0m  \n",fn_name,so_path,buffer,soname);
    void *so_handle = dlopen(buffer,RTLD_LAZY);
    SoHandler sh = NULL;
    sh = dlsym(so_handle,fn_name);
    if(sh == NULL){
        printf("no method found !\n");
    } else {
        sh(); 
    }
}

//使用简介
void usage(){
    printf("\n\033[0;32m");
    printf("# RunSo tools #\n");
    printf("build Number : %s \n\n",buildnum);
    printf("-n soname , without .so suffix \n\n");
    printf("-d so path , with right / \n\n");
    printf("-c function name to call . \n\tdefault : RunSo . \n\tThis Export Function Must be int (*SoHandler)()  \n\n");
    printf("-m call multiple so files , loop so dir \n\n");
    printf("example usage:  \n\t./runso -d ./item -n goso -c RunSo\n\t./runso -d ./item -m -c RunSo\n\n");
    printf("\033[0m\n");
}

void loopCallDirSo(char* path,char* fname){
      DIR *dir;
      struct dirent *ptr; 
      int len = 0;
      if((dir = opendir(path)) == NULL ){
          printf("can't open dir pathed : %s ",path);
          return;
      }
      printf("      loop dir so files , sopath : %s , call function name: %s \n",path,fname);
      while (( ptr = readdir(dir)) != NULL){
          if(ptr->d_type == DT_REG) {
              len = strlen(ptr->d_name);
              if(len>3){
                if(ptr->d_name[len-1] == 'o' && ptr->d_name[len-2] == 's' && ptr->d_name[len-3] == '.'){
                    ptr->d_name[len-3] = '\0';
                    RunSoFn(path,ptr->d_name,fname);
                }
              }
          }
      }
      closedir(dir);
}

//主函数
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

    if(RunArgs.sopath == NULL){
        usage();
        return 1; 
    }

    if(RunArgs.soname == NULL && RunArgs.multiple == 0){
        usage();
        return 1; 
    }

    if(RunArgs.fname == NULL){
        RunArgs.fname = "RunSo"; 
    }

    printf("\n \033[0;32m  Start Running RunSo Code !\033[0m\n");

    if(RunArgs.multiple == 0){
        RunSoFn(RunArgs.sopath,RunArgs.soname,RunArgs.fname);
    } else {
        loopCallDirSo(RunArgs.sopath,RunArgs.fname);    
    }

    printf("\n");
    return 0;
}
