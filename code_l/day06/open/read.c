#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDONLY);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n",fd);
    char buf[256] = {0};
    int ret = read(fd,buf,sizeof(buf)-1);
    ERROR_CHECK(ret,-1,"read");
    puts(buf);
    close(fd);
    return 0;
}

