#include "process_pool.h"

int main(int argc, char** argv)
{   
    int processNum = atoi(argv[3]);
    
    pProcess_data_t pData = (pProcess_data_t)calloc(processNum, sizeof(process_data_t));

    //1.循环创建子进程
    makeChild(processNum, pData);

    //2.创建tcp监听套接字
    int sfd = 0;
    tcpInit(&sfd, argv[1], argv[2]);
    //3.创建epoll监听文件描述符
    int epfd = epoll_create(1);
    epollAddFd(epfd, sfd);

    //循环的把父子进程之间通信的管道描述符交给epoll
    for(int i = 0; i < processNum; ++i){
        epollAddFd(epfd, pData[i].pipefd);
    }

    struct epoll_event *evs = (struct epoll_event*)calloc(processNum, sizeof(struct epoll_event));
    int readyNum = 0;
    int newFd = 0;
    char buf[8] = {0};

    while(1){
        readyNum = epoll_wait(epfd, evs, processNum, -1);
        for(int i = 0; i < readyNum; ++i){
            //如果是sfd就绪就说明有客户端建立连接
            if(evs[i].data.fd == sfd){
                newFd = accept(sfd, NULL, NULL);
                //循环查找空闲子进程，找到后把newfd传递给子进程
                for(int j = 0; j < processNum; ++j){
                    //找到空闲子进程
                    if(0 == pData[j].flag){
                        sendFd(pData[j].pipefd, newFd);
                        pData[j].flag = 1;
                        printf("child %d is busy\n", pData[j].pid);
                        break;
                    }
                }
                close(newFd);
            }
            else{
                //循环查找完成任务的子进程
                for(int j = 0; j < processNum; ++j){
                    //如果找到就读管道、并把子进程的状态置为空闲
                    if(evs[i].data.fd == pData[j].pipefd){
                        read(pData[j].pipefd, buf, sizeof(buf));//读的fd是父进程管道的写端？？？
                        pData[j].flag = 0;
                        printf("child %d is not busy\n", pData[j].pid);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

//子线程的写是fd[0],父进程的读是fd[1],好像也不冲突。