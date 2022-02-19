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
void TaskQueue::push(const ElemType & e)
{
	//RAII的技术解决死锁的问题
	MutexLockGuard autolock(_mutex);
	while(full()) {			//为了防止出现虚假唤醒(就是当wait被唤醒后应该再检查一次条件，唤醒后可能其它线程使full条件再一次满足），必须使用while进行判断
		_notFull.wait();
	}

	_que.push(e);
	//....return

	_notEmpty.notify();//通知消费者线程取数据
}

//pop函数运行在消费者线程
ElemType TaskQueue::pop()
{
	MutexLockGuard autolock(_mutex);
	while(empty()) {
		_notEmpty.wait();
	}

	//先从队列中获取数据,再pop
	ElemType tmp = _que.front();
	_que.pop();
	//....return
	_notFull.notify();
	

	return tmp;
}



}//end of namespace wd
