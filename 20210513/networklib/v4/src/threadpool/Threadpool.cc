 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 17:06:30
 ///
 
#include "Threadpool.hpp"

#include <unistd.h>

namespace wd
{

Threadpool::Threadpool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _queSize(queSize)
, _taskque(_queSize)
, _isExit(false)
{
	_threads.reserve(_threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit) {
		stop();
	}
}

void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx) {
		unique_ptr<Thread> up(new Thread(
			std::bind(&Threadpool::threadFunc, this)));
		_threads.push_back(std::move(up));
	}

	for(auto & pthread : _threads) {
		pthread->start();
	}
}


void Threadpool::addTask(Task && task)
{
	if(task) {
		_taskque.push(std::move(task));
	}
}

Task Threadpool::getTask()
{
	return _taskque.pop();
}


//运行在主线程
void Threadpool::stop()
{
	//在退出线程池之前，要确保任务都已经完成了
	while(!_taskque.empty()) {
		sleep(1);
	}

	_isExit = true;
	_taskque.wakeup();
	for(auto & pthread : _threads) {
		pthread->join();
	}
}

//每一个工作线程需要做的事情
void Threadpool::threadFunc()
{
	while(!_isExit) {
		Task taskcb = getTask();
		if(taskcb) {
			taskcb();// 执行任务的地方
		}
	}
}

//启动多个线程并执行，线程从任务队列拿出Tcpconnect对象执行回调函数加入的任务（Mytask的process方法）
}//end of namespace wd
