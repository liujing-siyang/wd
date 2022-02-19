#include <func.h>
void sigfunc(int signum, siginfo_t *info, void *p){
    printf("signum = %d\n",signum);
    printf("signo = %d\n", info->si_signo);
    printf("errno = %d\n", info->si_errno);
    printf("code = %d\n", info->si_code);
    printf("uid = %d\n",info->si_uid);
}
int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_sigaction = sigfunc;
    act.sa_flags = SA_SIGINFO;
    struct sigaction oldact;
    int ret = sigaction(SIGINT,&act,&oldact);
    ERROR_CHECK(ret,-1,"sigaction");
    while(1);
    return 0;
}

