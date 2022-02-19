 ///
 /// @file    Eventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-12 11:21:32
 ///
 
#include "Eventfd.hpp"

#include <unistd.h>
#include <stdio.h>
#include <sys/eventfd.h>
#include <poll.h>

namespace wd
{

Eventfd::Eventfd(EventCallback && cb)
: _evfd(createEventfd())
, _cb(std::move(cb))
, _isStarted(false)
{}

void Eventfd::start()
{
	struct pollfd pfd;
	pfd.fd = _evfd;
	pfd.events = POLLIN;

	_isStarted = true;
	int nready = -1;
	while(_isStarted) {
		//对文件描述符进行监听
		nready = poll(&pfd, 1, 5000);
		printf("nready:%d\n", nready);

		if(nready == 0) {
			printf(">> poll timeout!\n");
		} else if(nready == -1 && errno == EINTR) {
			continue;
		} else if(nready == -1) {
			perror("poll");
			return;
		} else {
			if(pfd.revents & POLLIN) {
				handleRead();//1. 对事件进行处理
				if(_cb) {	 //2. 执行任务
					_cb();//void process()
				}
			}
		}
	}
}

void Eventfd::stop()
{	_isStarted = false;	}


void Eventfd::wakeup()
{
	uint64_t one = 1;
	int ret = write(_evfd, &one, sizeof(one));
	if(ret != sizeof(one)) {
		perror("write");
	}
}

void Eventfd::handleRead()
{
	uint64_t howmany = 0;
	int ret = read(_evfd, &howmany, sizeof(howmany));
	if(ret != sizeof(howmany)) {
		perror("read");
	}
}



int Eventfd::createEventfd()
{
	int fd = eventfd(0, 0);
	if(fd < 0) {
		perror("eventfd");
	}
	return fd;
}

}//end of namespace wd
