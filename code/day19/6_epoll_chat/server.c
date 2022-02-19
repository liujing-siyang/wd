#include <head.h>

int main(int argc, char** argv)
{
    //创建sfd，用于与客户端建立连接
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    //把sfd， 与本地的端口号和ip进行绑定
    int ret = bind(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");

    //监听sfd， 并且最大监听的连接数为10
    ret = listen(sfd, 10);
    ERROR_CHECK(ret, -1, "listen");

    //accept函数接收对端的连接请求，并且返回一个新的文件描述符，
    //新的文件描述符用于与对端进行数据的交互
    int newFd = accept(sfd, NULL, NULL);
    ERROR_CHECK(newFd, -1, "accept");

    //使用epoll_create函数生成epfd，用于管理需要监听的文件描述符
    int epfd = epoll_create(1);
    //创建结构体，里面存储加入的文件描述符信息
    struct epoll_event event, evs[2];
    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    //epoll_ctl 函数的作用是把需要监听的文件描述符加入到epfd中
    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event);

    event.data.fd = newFd;
    epoll_ctl(epfd, EPOLL_CTL_ADD, newFd, &event);
    int readyNum = 0;
    char buf[128] = {0};
    while(1){
        //把需要监听的文件描述符加入到集合当中
        //epoll_wait函数用于监听就绪的文件描述符， 并且把就绪的问价描述符加入到evs中：
        readyNum  = epoll_wait(epfd, evs, 2, -1);
        for(int i = 0; i < readyNum; ++i){
            if(evs[i].data.fd == STDIN_FILENO){
                memset(buf, 0, sizeof(buf));
                read(STDIN_FILENO, buf, sizeof(buf));
                send(newFd, buf, strlen(buf)-1, 0);
            }
            if(evs[i].data.fd == newFd){
                memset(buf, 0, sizeof(buf));
                ret = recv(newFd, buf, sizeof(buf), 0);
                //如果recv的返回值是0，就代表对端断开连接
                if(0 == ret){
                    printf("bye,bye\n");
                    close(sfd);
                    close(newFd);
                    return 0;
                }
                printf("buf = %s\n", buf);
            }
        }
    }

    //关闭文件描述符
    close(sfd);
    close(newFd);
    return 0;
}

