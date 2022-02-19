 ///
 /// @file    Thread.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:30:46
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include <pthread.h>

#include <functional>
using std::function;

namespace wd
{

class Thread
{
public:
	using ThreadCallback = function<void()>;

	//使用右值引用是为了减少复制的开销
	Thread(ThreadCallback && cb)
	: _pthid(0)
	, _isRunning(false)
	, _cb(std::move(cb))  //注册回调函数
	{}

	~Thread();

	void start();
	void join();

private:
	//不希望该方法在类之外直接调用
	//同时要消除this指针的影响
	static void * threadFunc(void*);

private:
	pthread_t _pthid;
	bool _isRunning;
	ThreadCallback _cb;
};

}//end of nanmespace wd

#endif
