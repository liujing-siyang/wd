#include <func.h>
void sigfunc(int signum){
    printf("signum = %d\n",signum);
}
void mysleep(int sleepTime){
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = sigfunc;
    sigaction(SIGALRM,&act,NULL);
    
    sigset_t blkmask;
    sigemptyset(&blkmask);
    sigaddset(&blkmask,SIGALRM);
    sigprocmask(SIG_BLOCK,&blkmask,NULL);
    alarm(sleepTime);
    sigemptyset(&blkmask);
    sigsuspend(&blkmask);
}
int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = sigfunc;
    sigaction(SIGINT,&act,NULL);
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask,SIGINT);
    sigprocmask(SIG_BLOCK,&mask,NULL);
    time_t now;
    time(&now);
    printf("time = %s",ctime(&now));
    mysleep(5);
    time(&now);
    printf("time = %s",ctime(&now));
#if 0
    sigprocmask(SIG_UNBLOCK,&mask,NULL);
    pause();
#else
    sigset_t waitSet;//表示还要阻塞的信号
    sigemptyset(&waitSet);
    sigsuspend(&waitSet);
#endif
    return 0;
}

