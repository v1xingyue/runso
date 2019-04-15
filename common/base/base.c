#include <stdio.h>
#include "base.h"

void BaseInfo(){
    printf("ok this is base module for every modules .");
}

void BaseAdd(){
    base_number += 10;
    printf("\n======= >>> base.so Now number is : %d \n ",base_number);
}

void PrintArgs(struct _RunSoArgs *arg){
    printf("\n get global args point from base.so : \n path is : %s ",arg->sopath);
}
