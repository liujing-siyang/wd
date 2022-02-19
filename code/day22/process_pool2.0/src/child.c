#include "process_pool.h"

int makeChild(int processNum, pProcess_data_t pData)
{
    int fds[2];
    int childFd = 0;
    for(int i = 0; i < processNum; ++i){
        socketpair(AF_LOCAL, SOCK_STREAM, 0, fds);
        childFd = fork();//创建子进程
        if(0 == childFd)//子进程
        {
            close(fds[1]);//关闭管道写端
            childFunc(fds[0]);//子进程进行相应的操作
            exit(0);
        }
        //父进程
        close(fds[0]);//关闭读端
        pData[i].flag = 0;
        pData[i].pid = childFd;
        pData[i].pipefd = fds[1];//父进程通过写端传递数据
    }
    return 0;
}

int childFunc(int pipefd)
{
    int clientFd = 0;
    while(1){
        //接收父进程传来的文件描述符
        recvFd(pipefd, &clientFd);
        //跟客户端建立通信、发送数据
        transFile(clientFd);
        //发送完数据后，写管道通知自己完成数据交互，需要把状态信息置为空闲
        write(pipefd, "ok", 2);
        close(clientFd);
    }
    return 0;
}
