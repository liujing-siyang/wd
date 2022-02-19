#include <func.h>
void sigfunc(int signum){
    printf("before signum = %d\n",signum);
    sleep(5);
    printf("after signum = %d\n",signum);
}
int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = sigfunc;
    //act.sa_flags = SA_NODEFER;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask,SIGQUIT);
    int ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction int");
    //ret = sigaction(SIGQUIT,&act,NULL);
    //ERROR_CHECK(ret,-1,"sigaciton quit");
    while(1);
    return 0;
}

