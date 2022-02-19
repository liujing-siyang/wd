 ///
 /// @file    WorkerThread.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 17:10:03
 ///
 
#ifndef __WD_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__
#include "Thread.hpp"
#include "Threadpool.hpp"

namespace wd
{



class WorkerThread : public Thread
{
public:
	WorkerThread(Threadpool & threadpool)
	: _threadpool(threadpool)
	{}

private:
	void run()
	{
		//threadFunc在Threadpool中是私有的
		//所以WorkerThread应该设计为Threadpool的友元
		_threadpool.threadFunc();
	}

	Threadpool & _threadpool;
};


}//end of namesapce wd

#endif
