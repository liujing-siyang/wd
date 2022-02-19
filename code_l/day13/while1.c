#include <func.h>
void sigfunc(int signum){
    printf("signum = %d\n",signum);
    //如果不加换行，进程被信号终止时，缓冲区不会被清空
    //回调函数执行时处于中断上下文
    //exit(0);
}
int main()
{
    sighandler_t ret1 = signal(SIGINT,sigfunc);
    ERROR_CHECK(ret1,SIG_ERR,"signal");
    puts("begin sleeping!");
    sleep(5);
    puts("sleep ends!");
    sighandler_t ret2 = signal(SIGINT,SIG_IGN);
    ERROR_CHECK(ret2,SIG_ERR,"signal dfl");
    while(1);
    return 0;
}

