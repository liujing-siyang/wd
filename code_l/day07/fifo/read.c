#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int fdr = open(argv[1],O_RDONLY);
    puts("open!");
    ERROR_CHECK(fdr,-1,"open");
    char buf[128] = {0};
    read(fdr,buf,127);
    puts("read!");
    puts(buf);
    return 0;
}

