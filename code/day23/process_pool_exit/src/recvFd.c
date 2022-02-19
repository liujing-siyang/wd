#include "process_pool.h"

int recvFd(int pipefd, int *fd, char *exitFlag)
{
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));

    struct iovec iov;
    memset(&iov, 0, sizeof(iov));

    iov.iov_base = exitFlag;
    iov.iov_len = 1;

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

    recvmsg(pipefd, &msg, 0);
    *fd = *(int *)CMSG_DATA(cmsg);

    return 0;
}
