#include <func.h>
int main(int argc, char *argv[])
{
    // ./chat1 1.pipe 2.pipe
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    int fdw = open(argv[2],O_WRONLY);
    puts("chat1");
    char buf[128] = {0};
    while(1){
        memset(buf,0,sizeof(buf));
        read(STDIN_FILENO,buf,127);
        write(fdw,buf,strlen(buf));
        memset(buf,0,sizeof(buf));
        read(fdr,buf,127);
        puts(buf);
    }
    return 0;
}

