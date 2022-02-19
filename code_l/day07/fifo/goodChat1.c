#include <func.h>
int main(int argc, char *argv[])
{
    // ./chat1 1.pipe 2.pipe
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    int fdw = open(argv[2],O_WRONLY);
    puts("chat1");
    fd_set rdset;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset);
        char buf[128];
        struct timeval timeout;
        timeout.tv_sec = 2;
        timeout.tv_usec = 500000;
        int sret = select(fdr+1,&rdset,NULL,NULL,&timeout);
        if(sret == 0){
            puts("timeout!");
        }
        else{
            if(FD_ISSET(STDIN_FILENO,&rdset)){
                puts("msg from stdin");
                memset(buf,0,sizeof(buf));
                int ret = read(STDIN_FILENO,buf,sizeof(buf)-1);
                if(ret == 0){
                    puts("I quit");
                    write(fdw,"nishigehaoren",13);
                    break;
                }
                write(fdw,buf,strlen(buf));
            }
            if(FD_ISSET(fdr,&rdset)){
                puts("msg from pipe");
                memset(buf,0,sizeof(buf));
                int ret = read(fdr,buf,sizeof(buf)-1);
                if(ret == 0){
                    puts("over");
                    break;
                }
                puts(buf);
            }
        }
    }
    close(fdw);
    close(fdr);
    return 0;
}

