 ///
 /// @file    TaskQueue.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 14:52:15
 ///

#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "MutexLock.hpp"
#include "Condition.hpp"
#include "Task.hpp"

#include <queue>
using std::queue;


namespace wd
{

using ElemType  = Task *;

class TaskQueue
{
public:
	TaskQueue(size_t sz);
	bool empty() const;
	bool full() const;
	void push(const ElemType & );//常量指针的引用
	ElemType pop();

private:
	size_t _queSize;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}//end of namespace wd

#endif
