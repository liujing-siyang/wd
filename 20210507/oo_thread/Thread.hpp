 ///
 /// @file    Thread.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:30:46
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include <pthread.h>

namespace wd
{

class Thread
{
public:
	Thread()
	: _pthid(0)
	, _isRunning(false)
	{}

	virtual ~Thread();

	void start();
	void join();

private:
	virtual void run() = 0;//实现任务
	//不希望该方法在类之外直接调用
	//同时要消除this指针的影响
	static void * threadFunc(void*);

private:
	pthread_t _pthid;
	bool _isRunning;
};

}//end of nanmespace wd

#endif
