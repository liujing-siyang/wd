 ///
 /// @file    TimerManager.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-10-23 09:53:37
 ///
 
#include "TimerManager.hpp"

#include "TimerTask.hpp"

//#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/timerfd.h>
#include <poll.h>

#include <string>
#include <algorithm>
#include <iostream>

namespace wd
{

TimerManager::TimerManager()
: _fd(createTimerfd())
, _isStarted(false)
, _currentIndex(0)
{
	//开辟空间，初始化vector<list<TimerTask *>> _timeWheelList
	_timeWheelList.reserve(kSize);
	for(size_t idx = 0; idx < kSize; ++idx) {
		_timeWheelList.push_back(list<TimerTask*>());
	}
}

void TimerManager::start()
{
	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	//开启定时器
	setTimerfd(1, 1);//每一秒超时一次

	_isStarted = true;
	while(_isStarted) {
		int nready = ::poll(&pfd, 1, 5000);
		if(nready == -1  &&  errno == EINTR)
			continue;
		else if(nready == -1) {
			perror("poll");
			return;
		} else if(nready == 0) {
			printf("poll timeout!\n");
		} else {
			std::cout << "111" << std::endl;
			handleRead();
			handleTask();
		}
	}
}
	
void TimerManager::stop()
{
	setTimerfd(0, 0);
	if(_isStarted)
		_isStarted = false;
}

void TimerManager::addTask(TimerTask * timerTask)
{
	if(timerTask) {
		/* 根据seconds确定在哪一个时间槽slot */
		int idx = (timerTask->getTimeInterval() + _currentIndex) % kSize;
		/* 放入时间槽*/
		_timeWheelList[idx].push_back(timerTask);
		/* 确定圈数 */
		int count = timerTask->getTimeInterval() / kSize;
		timerTask->setCount(count);
	}
}

void TimerManager::removeTask(TimerTask * timerTask)
{
	if(timerTask) {
		for(auto & slot : _timeWheelList) {
			for(auto ptask : slot) {
				if(ptask == timerTask) {
					slot.remove(ptask);
					return;
				}
			}
		}
	}
}

int TimerManager::createTimerfd()
{
	int fd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(fd < 0) {
		perror("timerfd_create");
	}
	return fd;
}

void TimerManager::setTimerfd(int initialTime, int periodicTime)
{
	struct itimerspec value;
	value.it_value.tv_sec = initialTime;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = periodicTime;
	value.it_interval.tv_nsec = 0;

	int ret = ::timerfd_settime(_fd, 0, &value, nullptr);
	if(ret < 0) {
		perror("timerfd_settime");
	}
}

void TimerManager::handleRead()
{
	uint64_t howmany = 0;
	int ret = ::read(_fd, &howmany, sizeof(howmany));
	if(ret != sizeof(howmany)) {
		perror("read");
	}
}

void TimerManager::handleTask()
{
	++_currentIndex;
	_currentIndex %= kSize;

	list<TimerTask *> cacheList;

	auto & slot = _timeWheelList[_currentIndex];
	for(auto iter = slot.begin(); iter != slot.end();) {
		
		if((*iter)->getCount() <= 0) {
			//先缓存
			auto tmp = *iter;
			cacheList.push_back(tmp);
			//再从当前槽中删除掉
			iter = slot.erase(iter);// 删除当前元素之后，得到了下一个元素的位置，这里如果如果迭代器为end可以跳出循环
			//再将其添加到槽中
			addTask(tmp);
			//之所以将任务从槽中删除又添加是因为此时_currentIndex和之前不一样，下一次重新触发任务时应该放到相应的槽。
			//拿本例来讲，此时_currentIndex为3，定时为3，那么应该将其添加到6号槽以在下一次再次触发任务
		} 
		else {
			(*iter)->decreaseCount();
			++iter;
		}
	}

	//执行所有的定时器任务
	for(auto ptask : cacheList) {
		ptask->process();
	}
}

}//end of namespace wd
