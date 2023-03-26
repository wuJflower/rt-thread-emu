#include "rtthread/3.0.3/include/libc/rtdef.h"


/* 软件延时 */
void delay(rt_uint32_t count){
    for(;count!=0;count --){}
}





