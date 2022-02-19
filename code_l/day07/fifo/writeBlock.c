#include <func.h>
int main(int argc, char *argv[])
{
    // writeBlock 1.pipe
    ARGS_CHECK(argc,2);
    int fdr = open(argv[1],O_RDWR);
    int fdw = open(argv[1],O_RDWR);
    puts("established");
    fd_set rdset;
    fd_set wrset;
    int cnt = 0;
    char wrbuf[4096] = {0};
    char rdbuf[4096] = {0};
    while(1){
        FD_ZERO(&rdset);
        FD_ZERO(&wrset);
        FD_SET(fdr,&rdset);
        FD_SET(fdw,&wrset);
        select(fdw+1,&rdset,&wrset,NULL,NULL);
        if(FD_ISSET(fdw,&wrset)){
            printf("cnt = %d", ++cnt);
            write(fdw,wrbuf,4096);
            puts("write success!");
        }
        if(FD_ISSET(fdr,&rdset)){
            read(fdr,rdbuf,2048);
            puts("read success!");
        }
    }
    return 0;
}

