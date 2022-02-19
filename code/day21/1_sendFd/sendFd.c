#include <head.h>

int main(int argc, char** argv)
{
    int fds[2];
    pipe(fds);
    if(fork()){
        int fd = open("file", O_RDWR);
        printf("fd = %d\n", fd);
        //通过管道传递文件描述符，传递的仅仅是一个整型值
        write(fds[1], &fd, sizeof(int));
        wait(NULL);
    }

    else{
        int childFd = 0;
        int ret = read(fds[0], &childFd, sizeof(int));
        ERROR_CHECK(ret, -1, "read1");
        printf("childFd = %d\n", childFd);

        char buf[64] = {0};
        ret = read(childFd, buf, sizeof(buf));
        ERROR_CHECK(ret, -1, "read2");

        printf("buf = %s\n", buf);
    }
    return 0;
}

