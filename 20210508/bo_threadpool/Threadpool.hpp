 ///
 /// @file    Threadpool.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 16:35:50
 ///
 
#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__

#include "TaskQueue.hpp"
#include "Thread.hpp"
#include "Task.hpp"

#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;


namespace wd
{

class Threadpool
{
public:
	Threadpool(size_t threadNum, size_t queSize);
	~Threadpool();
	void start();
	void stop();
	void addTask(Task &&);
private:
	Task getTask();
	void threadFunc();

private:
	size_t _threadNum;
	size_t _queSize;

	vector<unique_ptr<Thread>> _threads;
	TaskQueue _taskque;
	bool _isExit;
};

}//end of namespaced wd


#endif



