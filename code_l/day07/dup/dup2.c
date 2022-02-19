#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n",fd);
    dup2(STDOUT_FILENO,10);
    dup2(fd,STDOUT_FILENO);
    printf("You can't see me!\n");

    dup2(10,STDOUT_FILENO);
    printf("You can see me!\n");

    close(fd);
    close(10);
    return 0;
}

