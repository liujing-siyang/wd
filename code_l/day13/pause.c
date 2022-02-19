#include <func.h>
void sigfunc(int signum){
    printf("signum is %d\n", signum);
}
int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = sigfunc;
    sigaction(SIGINT,&act,NULL);
    pause();
    return 0;
}

