#include <func.h>
int main()
{
    int fds[2];
    pipe(fds);
    printf("fds[0] = %d\n",fds[0]);//read
    printf("fds[1] = %d\n",fds[1]);//write
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child\n");
        close(fds[1]);//关闭写端
        char buf[128] = {0};
        read(fds[0],buf,sizeof(buf)-1);
        puts(buf);
        exit(0);
    }
    else{
        printf("I am parent\n");
        close(fds[0]);//关闭读端
        write(fds[1],"hello",5);
        wait(NULL);
        exit(0);
    }
}

