 ///
 /// @file    Timer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-12 11:21:32
 ///
 
#include "Timer.hpp"

#include <unistd.h>
#include <stdio.h>
#include <sys/timerfd.h>
#include <poll.h>

namespace wd
{

Timer::Timer(int initsec, int periodicsec, TimerCallback && cb)
: _timerfd(createTimerfd())
, _initTime(initsec)
, _periodicTime(periodicsec)
, _cb(std::move(cb))
, _isStarted(false)
{}

void Timer::start()
{
	struct pollfd pfd;
	pfd.fd = _timerfd;
	pfd.events = POLLIN;

	setTimerfd(_initTime, _periodicTime);//启动定时器

	_isStarted = true;
	int nready = -1;
	while(_isStarted) {
		//对文件描述符进行监听
		nready = poll(&pfd, 1, 5000);//定时器到设定的时间触发一次写操作唤醒
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
					_cb();
				}
			}
		}
	}
}

void Timer::stop()
{	
	if(_isStarted) {
		setTimerfd(0, 0);//停止计时器
		_isStarted = false;	
	}
}

void Timer::handleRead()
{
	uint64_t howmany = 0;
	int ret = read(_timerfd, &howmany, sizeof(howmany));
	if(ret != sizeof(howmany)) {
		perror("read");
	}
}



int Timer::createTimerfd()
{
	int fd = timerfd_create(CLOCK_REALTIME, 0);
	if(fd < 0) {
		perror("eventfd");
	}
	return fd;
}

void Timer::setTimerfd(int initsec, int periodicsec)
{
	struct itimerspec value;
	value.it_value.tv_sec = initsec;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = periodicsec;
	value.it_interval.tv_nsec = 0;
	int ret = timerfd_settime(_timerfd, 0, &value, nullptr);
	if(ret < 0) {
		perror("timerfd_settime");
	}
}

}//end of namespace wd
