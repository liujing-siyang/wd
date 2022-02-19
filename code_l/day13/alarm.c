#include <func.h>
void sigfunc(int signum){
    printf("signum = %d\n",signum);
}
int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = sigfunc;
    sigaction(SIGALRM,&act,NULL);
    int ret = alarm(3);
    printf("first ret = %d\n",ret);
    sleep(2);
    ret = alarm(2);
    printf("first ret = %d\n",ret);
    pause();
    pause();
    return 0;
}

