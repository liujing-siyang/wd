#include <func.h>
void sigfunc(int signum){
    time_t now;
    time(&now);
    puts(ctime(&now));
}
int main()
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = sigfunc;
    sigaction(SIGALRM, &act, NULL);
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 3;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    sigfunc(0);
    sleep(2);
    while(1);
    return 0;
}

