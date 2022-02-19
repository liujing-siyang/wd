#include "process_pool.h"

int makeChild(int processNum, pProcess_data_t pData)
{
    int fds[2];
    int childFd = 0;
    for(int i = 0; i < processNum; ++i){
        socketpair(AF_LOCAL, SOCK_STREAM, 0, fds);
        childFd = fork();
        if(0 == childFd){
            close(fds[1]);
            childFunc(fds[0]);
            exit(0);
        }
        close(fds[0]);
        pData[i].flag = 0;
        pData[i].pid = childFd;
        pData[i].pipefd = fds[1];
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
        send(clientFd, "helloclient", 11, 0);
        //发送完数据后，写管道通知自己完成数据交互，需要把状态信息置为空闲
        write(pipefd, "ok", 2);//写端不是已经关闭了吗,pipefd是子线程的读端呀？？？
        close(clientFd);
    }
    return 0;
}
