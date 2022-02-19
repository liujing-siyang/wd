 ///
 /// @file    EventLoop.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-11 15:56:30
 ///

#include "EventLoop.hpp"
#include "TcpConnection.hpp"
#include "Acceptor.hpp"

#include <unistd.h>


namespace wd
{

EventLoop::EventLoop(Acceptor & acceptor)
: _efd(createEpollfd())
, _acceptor(acceptor)
, _isLooping(false)
, _evtList(1024)
{
	addEpollReadFd(_acceptor.fd());
}
	
EventLoop::~EventLoop()
{
	if(_efd) {
		close(_efd);
	}
}


void EventLoop::loop()
{
	_isLooping = true;
	while(_isLooping) {
		waitEpollfd();
	}
}

void EventLoop::unloop()
{
	_isLooping = false;
}
//采用移动语义，因为只需要使用一次（给对象数据成员赋值）
void EventLoop::setConnectionCallback(TcpConnectionCallback && cb)
{
	_onConnectionCb = std::move(cb);//显式使用move,考虑完美转发
}

void EventLoop::setMessageCallback(TcpConnectionCallback && cb)
{
	_onMessageCb = std::move(cb);
}

void EventLoop::setCloseCallback(TcpConnectionCallback && cb)
{
	_onCloseCb = std::move(cb);
}

void EventLoop::waitEpollfd()
{
	int nready = 0;
	do {
		nready = ::epoll_wait(_efd, &*_evtList.begin(), _evtList.size(), 5000);
	}while(nready == -1 && errno == EINTR);

	if(nready == -1) {
		perror("epoll_wait");
		return;
	} else if(nready == 0) {
		printf(">> epoll_wait timeout!\n");
	} else {
		//nready > 0
		if(nready == _evtList.size()) {
			_evtList.resize(2 * nready);
		}

		for(int idx = 0; idx < nready; ++idx) {
			int fd = _evtList[idx].data.fd;
			if(fd == _acceptor.fd() &&
				_evtList[idx].events & EPOLLIN) {
				handleNewConnection();
			} else {
				if(_evtList[idx].events & EPOLLIN) {
					handleMessage(fd);
				}
			}
		}
	}
}

void EventLoop::handleNewConnection() {
	int peerfd = _acceptor.accept();
	addEpollReadFd(peerfd);
	TcpConnectionPtr conn(new TcpConnection(peerfd));

	//自定义	，传参不使用移动语义，因为后续的连接还要继续使用
	//EventLoop对象的数据成员--回调函数，只有一份，move后就不能使用了，而后续的连接还需要使用该数据成员，所以不能使用移动语义
	conn->setConnectionCallback(_onConnectionCb);//处理连接回调
	conn->setMessageCallback(_onMessageCb);//处理信息回调
	conn->setCloseCallback(_onCloseCb);//处理连接关闭回调

	_conns.insert(std::make_pair(peerfd, conn));
	//触发新连接到来时的事件处理器
	conn->handleConnectionCallback();
}

void EventLoop::handleMessage(int fd)
{
	//1. 通过fd找到TcpConnection对象
	auto iter = _conns.find(fd);
	if(iter != _conns.end()) {
		//2. 判断该连接是否断开
		bool isColsed = iter->second->isClosed();
		//2.1 如果连接断开，执行连接断开时的事件处理器
		if(isColsed) {
			iter->second->handleCloseCallback();
			delEpollReadFd(fd);
			_conns.erase(iter);
		} else {
		//2.2 如果连接没有断开，执行消息到达时的事件处理器
			iter->second->handleMessageCallback();
		}
	}
}





int EventLoop::createEpollfd()
{
	int fd = epoll_create1(0);
	if(fd < 0) {
		perror("epoll_create1");
	}
	return fd;
}


void EventLoop::addEpollReadFd(int fd)
{
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = fd;
	int ret = ::epoll_ctl(_efd, EPOLL_CTL_ADD, fd, &ev);
	if(ret < 0) {
		perror("epoll_ctl");
	}
}

void EventLoop::delEpollReadFd(int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	int ret = ::epoll_ctl(_efd, EPOLL_CTL_DEL, fd, &ev);
	if(ret < 0) {
		perror("epoll_ctl");
	}
}
}//end of namespace wd
