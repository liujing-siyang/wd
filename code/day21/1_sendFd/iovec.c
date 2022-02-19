#include <head.h>

int main(int argc, char** argv)
{
    struct iovec iov[2];
    memset(iov, 0, sizeof(iov));

    char buf1[10] = {0};
    strcpy(buf1, "hello");
    char buf2[10] = {0};
    strcpy(buf2, "world");

    iov[0].iov_base = buf1;
    iov[0].iov_len = strlen(buf1);
    iov[1].iov_base = buf2;
    iov[1].iov_len = strlen(buf2);

    //把iovec结构体的两个buf内容打印到屏幕上
    writev(STDOUT_FILENO, iov, 2);
    return 0;
}

