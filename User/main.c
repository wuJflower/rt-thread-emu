#include "rtthread/3.0.3/include/libc/rtdef.h"


/* 软件延时 */
void delay(rt_uint32_t count){
    for(;count!=0;count --){}
}

int flag1 = 0;
int flag2 = 0;

/* 线程是一个独立的函数，函数主题无限循环且不能返回 */
/* 线程1 切换flag1 */
void flag1_thread_entry(void *p_arg){
    for(;;){
        flag1 = 1; 
        delay(1000);
        flag1 = 0;
        delay(1000);

        /* 手动切换 */
        rt_schedule();
    }

}



/* 线程2 */
/**
 * @brief 线程2 
 * 延时循环改变flag2
 * 
 * @param p_arg 
 * 线程输入参数 
 */
void  flag2_thread_entry(void *p_arg){
    for(;;){

        flag2 = 1; 
        delay(1000);
        flag2 = 0; 
        delay(1000);

        /* 手动调度 */
        rt_schedule();
    }
}



