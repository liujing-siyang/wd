 ///
 /// @file    TaskQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 14:55:28
 ///
 
#include "TaskQueue.hpp"

namespace wd
{

TaskQueue::TaskQueue(size_t sz)
: _queSize(sz)
, _que()
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{}

bool TaskQueue::empty() const
{
	return _que.size() == 0;
}

bool TaskQueue::full() const
{
	return _que.size() == _queSize;
}

//push函数运行在生产者线程
void TaskQueue::push(int number)
{
	//RAII的技术解决死锁的问题
	MutexLockGuard autolock(_mutex);
	while(full()) {			//为了防止出现虚假唤醒，必须使用while进行判断
		_notFull.wait();
	}

	_que.push(number);
	//....return

	_notEmpty.notify();//通知消费者线程取数据
}

//pop函数运行在消费者线程
int TaskQueue::pop()
{
	MutexLockGuard autolock(_mutex);
	while(empty()) {
		_notEmpty.wait();
	}

	//先从队列中获取数据,再pop
	int tmp = _que.front();
	_que.pop();
	//....return
	_notFull.notify();
	

	return tmp;
}



}//end of namespace wd
