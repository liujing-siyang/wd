 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:34:00
 ///
 
#include "Thread.hpp"
#include <stdio.h>

namespace wd
{

Thread::~Thread()
{
	if(_isRunning) {
		pthread_detach(_pthid);
	}
}

//start函数中是有this指针
void Thread::start()
{
	if(pthread_create(&_pthid, nullptr, threadFunc, this)) {//threadFunc需要调用线程初始化注册的回调函数，所以要传this指针，就是表示调用本对象的函数
		perror("pthread_create");
		return;
	}

	_isRunning = true;
}

//该函数是静态的，没有this指针;
//所以只能通过传递参数来达到目的
void * Thread::threadFunc(void * arg)
{
	//子线程入口函数要执行的任务就是run所代表的
	Thread * pthread = static_cast<Thread*>(arg);//强制转换
	if(pthread) {
		pthread->_cb(); //调用回调函数
	}

	return nullptr;
}00

void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid,nullptr);
		_isRunning = false;
	}
}


}// end of namesapce wd
