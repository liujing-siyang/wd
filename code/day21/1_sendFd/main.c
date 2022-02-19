#include <head.h>

int sendFd(int pipefd, int fd)
{
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));

    struct iovec iov;
    memset(&iov, 0, sizeof(iov));

    char buf[10] = {0};
    strcpy(buf, "hello");
    iov.iov_base = buf;
    iov.iov_len = strlen(buf);

    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;//结构体个数

    //cmsghdr结构体大小使用CMSG_LEN获得,这里时传fd的长度所以是sizeof(int)
    int len = CMSG_LEN(sizeof(int));

    //如果结构体里面含有柔性数组，优先使用堆空间
    struct cmsghdr *cmsg = (struct cmsghdr*)calloc(1, len);

    cmsg->cmsg_len = len;
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    //把文件描述符传到柔性数组中
    //unsigned char * CMSG_DATA(struct cmsghdr * cmsg)
    *(int *)CMSG_DATA(cmsg) = fd;

    msg.msg_control = cmsg;
    msg.msg_controllen = len;

    sendmsg(pipefd, &msg, 0);
    return 0;
}
int recvFd(int pipefd, int *fd)//fd为传入传出参数
{
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));

    struct iovec iov;
    memset(&iov, 0, sizeof(iov));

    char buf[10] = {0};
    strcpy(buf, "hello");
    iov.iov_base = buf;
    iov.iov_len = strlen(buf);

    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    //cmsghdr结构体大小使用CMSG_LEN获得
    int len = CMSG_LEN(sizeof(int));

    //如果结构体里面含有柔性数组，优先使用堆空间
    struct cmsghdr *cmsg = (struct cmsghdr*)calloc(1, len);

    cmsg->cmsg_len = len;
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    msg.msg_control = cmsg;
    msg.msg_controllen = len;

    recvmsg(pipefd, &msg, 0);//先接收再获取fd
    *fd = *(int *)CMSG_DATA(cmsg);

    return 0;
}
int main(int argc, char** argv)
{
    int fds[2];
    //创建一对套接口用于传递文件描述符
    socketpair(AF_LOCAL, SOCK_STREAM, 0, fds);
    //父进程传递
    if(fork()){
        close(fds[0]);//关闭读端
        int fd = open("file", O_RDWR);
        printf("fd = %d\n", fd);
        sendFd(fds[1], fd);
        write(fd, "world", 5);
        wait(NULL);
    }

    //子进程接收文件描述符
    else{
        close(fds[1]);//关闭写端
        int childFd = 0;
        recvFd(fds[0], &childFd);
        //接收的文件描述符和父进程的fd指向同一个文件
        printf("childFd = %d\n", childFd);

        char buf[64] = {0};
        int ret = read(childFd, buf, sizeof(buf));
        ERROR_CHECK(ret, -1, "read2");

        printf("buf = %s\n", buf);
    }
    return 0;
}

//文件描述符传递后，虽然父进程和子进程的文件描述符数值不同，但是是指向同一个文件
//通过write函数往文件描述符中写入数据发现文件中的数据被覆盖了可以验证