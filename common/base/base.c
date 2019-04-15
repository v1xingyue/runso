#include <stdio.h>
#include "base.h"

void BaseInfo(){
    printf("ok this is base module for every modules .");
}

void BaseAdd(){
    base_number += 10;
    printf("\n======= >>> base.so Now number is : %d \n ",base_number);
}

