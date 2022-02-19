#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_WRONLY);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n",fd);
    int ret = write(fd,"howareyou",9);
    ERROR_CHECK(ret,-1,"write");
    close(fd);
    return 0;
}

