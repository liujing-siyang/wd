 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 17:06:30
 ///
 
#include "Threadpool.hpp"
#include "WorkerThread.hpp"

#include <unistd.h>

namespace wd
{

Threadpool::Threadpool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _queSize(queSize)
, _taskque(_queSize)
, _isExit(false)
{
	_threads.(_threadNum);
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
		unique_ptr<Thread> up(new WorkerThread(*this));
		_threads.push_back(std::move(up));
	}

	for(auto & pthread : _threads) {
		pthread->start();
	}
}


void Threadpool::addTask(Task *ptask)
{
	if(ptask) {
		_taskque.push(ptask);
	}
}

Task * Threadpool::getTask()
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
	for(auto & pthread : _threads) {
		pthread->join();
	}
}

//每一个工作线程需要做的事情
void Threadpool::threadFunc()
{
	while(!_isExit) {
		Task * ptask = getTask();
		if(ptask) {
			ptask->process();//执行任务的地方
		}
	}
}


}//end of namespace wd
