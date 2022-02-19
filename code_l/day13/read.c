#include <func.h>
void sigfunc(int signum){
    printf("signum = %d\n",signum);
}
int main()
{
    //sighandler_t ret1 = signal(SIGINT,sigfunc);
    //ERROR_CHECK(ret1,SIG_ERR,"signal");
    //使用signal 低速系统调用会重启
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = sigfunc;
    int ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");
    //使用sigaction 默认情况下低速系统调用不会重启
    char buf[128] = {0};
    read(STDIN_FILENO,buf,127);
    puts(buf);
    return 0;
}

