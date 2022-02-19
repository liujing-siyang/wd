#include "../include/threadpool.h"
int exitPipe[2];
void sigFunc1(int sigNum)
{
    printf("sig is comming\n");
    //异步拉起同步
    write(exitPipe[1], &sigNum, 4);
}
int main(int argc, char** argv)
{
    int threadNum = atoi(argv[3]);

    pipe(exitPipe);

    //父进程负责收SIGUSR1信号，子进程负责
    if(fork()){
        close(exitPipe[0]);
        signal(SIGUSR1, sigFunc1);
        wait(NULL);
        exit(0);
    }

    close(exitPipe[1]);
    //线程池的初始化
    threadPool_t threadPool;
    threadPoolInit(&threadPool, threadNum);

    //线程池的启动
    threadPoolStart(&threadPool);
    //初始化tcp监听套接字
    int sfd;
    tcpInit(&sfd, argv[1], argv[2]);

    int epfd = epoll_create(1);

    epollAddFd(epfd, sfd);
    epollAddFd(epfd, exitPipe[0]);

    int readyNum = 0;
    int newFd = 0;
    struct epoll_event evs[2]; 
    memset(evs, 0, sizeof(evs));
    while(1){
        readyNum = epoll_wait(epfd, evs, 2, -1);
        for(int i = 0; i < readyNum; ++i){
            if(evs[i].data.fd == sfd){
                newFd = accept(sfd, NULL, NULL);
                pNode_t pNode = (pNode_t)calloc(1, sizeof(Node_t));
                pNode->clientFd = newFd;
                pthread_mutex_lock(&threadPool.Que.mutex);
                queInsert(&threadPool.Que, pNode);
                pthread_cond_signal(&threadPool.Que.cond);
                pthread_mutex_unlock(&threadPool.Que.mutex);
            }
            //如果管道的读端就绪，就说明信号到了，开始通知线程退出
            if(evs[i].data.fd == exitPipe[0]){
                //第一种退出方式，比较暴力
                /* for(int j = 0; j < threadNum; ++j){ */
                /*     pthread_cancel(threadPool.pthid[j]); */
                /* } */

                //第二种退出方式
                //标志位设置为1的时候代表通知子线程退出
                threadPool.Que.exitFlag = 1;
                pthread_cond_broadcast(&threadPool.Que.cond);

                //循环等待子线程
                for(int j = 0; j < threadNum; ++j){
                    pthread_join(threadPool.pthid[j], NULL);
                }
                //子进程退出
                exit(0);
            }
        }
    }
    
    return 0;
}

