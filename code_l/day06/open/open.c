#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDONLY|O_CREAT|O_EXCL, 0777);
    //依然受到掩码的影响
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n",fd);
    close(fd);
    return 0;
}

