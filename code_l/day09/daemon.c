#include <func.h>
void Daemon(){
    const int MAXFD = 64;
    if(fork() != 0){
        exit(0); //父进程退出 守护进程成孤儿
    }
    setsid();
    chdir("/");
    umask(0);
    for(int i = 0; i < MAXFD; ++i){
        close(i);
    }
}
int main()
{
    Daemon();
    while(1){
        sleep(1);
    }
    return 0;
}

