///
/// @file    Thread.h
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-05-05 16:24:33
///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.hpp"

#include <pthread.h>

#include <iostream>
#include <functional>
using std::cout;
using std::endl;

namespace wd
{

class Thread
: Noncopyable
{
public:
	using ThreadCallback = std::function<void()>;

	Thread(ThreadCallback && cb)
	: _pthid(0)
	, _isRunning(false)
	, _cb(std::move(cb))
	{	cout << "Thread(ThreadCallback &&)" << endl;	}

	~Thread();

	void start(); //开启线程 ==> pthread_create
	void join();  //回收线程

private:
	static void * threadFunc(void * arg);//线程函数执行体

private:
	pthread_t _pthid;// 线程id
	bool _isRunning;
	ThreadCallback _cb;
};
}//end of namespace wd

#endif

