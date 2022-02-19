#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("\n");//坑，先打印一个换行
    close(STDOUT_FILENO);
    int newfd = dup(fd);//newfd == 1
    ERROR_CHECK(newfd,-1,"newfd");
    printf("newfd = %d\n",newfd);
    printf("can you see me?\n");
    close(fd);
    close(newfd);
    return 0;
}

