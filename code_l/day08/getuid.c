#include <func.h>
int main(int argc, char *argv[])
{
    printf("uid = %d, euid = %d\n",getuid(), geteuid());
    ARGS_CHECK(argc,2);
    int fd = open(argv[1], O_RDWR);
    write(fd,"hello",5);
    close(fd);
    return 0;
}

