 ///
 /// @file    Thread.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:30:46
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.hpp"
#include <pthread.h>

namespace wd
{

//在代码的可读性上是有很大空间，但并没有产生额外的开销
class Test: Copyable
{};

class Thread : Noncopyable
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

	//禁止复制，将拷贝构造函数和赋值运算符函数私有化
	//C++11之前的写法
	/* Thread(const Thread &); */
	/* Thread & operator=(const Thread&); */
	
	//C++11, 该方法在类中被删除了
	/* Thread(const Thread &) = delete; */
	/* Thread & operator=(const Thread&) = delete; */

private:
	pthread_t _pthid;
	bool _isRunning;
};

}//end of nanmespace wd

#endif
