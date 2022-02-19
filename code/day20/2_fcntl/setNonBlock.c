#include <head.h>

//使用fcntl函数把文件描述符设置为非阻塞的
int setNonBlock(int fd)
{
    int status = 0;
    status = fcntl(fd, F_GETFL);
    
    status |= O_NONBLOCK;
    //把文件描述符设置为非阻性的
    fcntl(fd, F_SETFL, status);
    return 0;
}
int main(int argc, char** argv)
{
    char buf[128] = {0};
    setNonBlock(STDIN_FILENO);
    read(STDIN_FILENO, buf, sizeof(buf));
    printf("buf = %s\n", buf);
    return 0;
}

