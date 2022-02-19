 ///
 /// @file    TaskQueue.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 14:52:15
 ///

#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "MutexLock.hpp"
#include "Condition.hpp"

#include <queue>
using std::queue;


namespace wd
{

class TaskQueue
{
public:
	TaskQueue(size_t sz);
	bool empty() const;
	bool full() const;
	void push(int);
	int pop();

private:
	size_t _queSize;
	queue<int> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}//end of namespace wd

#endif
