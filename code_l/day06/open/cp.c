#include <func.h>
int main(int argc, char *argv[])
{
    // ./cp srcs dest
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open");
    int fdw = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
    ERROR_CHECK(fdw,-1,"open");
    time_t beg = time(NULL);
    char buf[409600] = {0};
    while(1){
        memset(buf,0,sizeof(buf));
        int ret = read(fdr,buf,sizeof(buf));
        if(ret == 0){
            break;
        }
        write(fdw,buf,ret);
    }
    time_t end = time(NULL);
    printf("total time = %ld\n", end-beg);
    close(fdr);
    close(fdw);
    return 0;
}

