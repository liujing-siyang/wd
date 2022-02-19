#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child\n");
        write(fd,"hello",5);
    }
    else{
        printf("I am parent\n");
        sleep(1);
        char buf[6] = {0};
        read(fd,buf,5);
        printf("I am parent, buf = %s\n",buf);
    }
    return 0;
}

