#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int ret = mkfifo(argv[1],0666);
    ERROR_CHECK(ret, -1, "mkfifo");
    pid_t pid = fork();
    if(pid == 0){
        int fdw = open(argv[1],O_WRONLY);
        ERROR_CHECK(fdw,-1,"open fdw");
        write(fdw,"msgfromchild",12);
        exit(0);
    }
    else{
        int fdr = open(argv[1],O_RDONLY);
        ERROR_CHECK(fdr,-1,"open fdr");
        char buf[128] = {0};
        read(fdr,buf,sizeof(buf)-1);
        puts(buf);
        wait(NULL);
        unlink(argv[1]);
        exit(0);
    }
}

