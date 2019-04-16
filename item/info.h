#include <stdio.h>

static int big_number = 0;

int Hello(int);

typedef void (*CallBack)();

void runCallBack(CallBack cb);
