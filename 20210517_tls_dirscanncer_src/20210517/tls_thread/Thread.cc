 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:34:00
 ///
 
#include "Thread.hpp"
#include <stdio.h>

namespace wd
{

namespace current_thread
{
__thread const char * name = "wd thread";
}// end of namespace current_thread


struct ThreadData
{
	ThreadData(const string & name,
			Thread::ThreadCallback && cb)
	: _name(name)
	, _cb(std::move(cb))
	{}

	void runInThread()
	{
		wd::current_thread::name = (_name != string() ? _name.c_str() : "wd thread");//判断_name是否为空
		if(_cb) {
			_cb(); //调用回调函数
		}
	}

	std::string _name;
	Thread::ThreadCallback _cb;

};

Thread::~Thread()
{
	if(_isRunning) {
		pthread_detach(_pthid);
	}
}

//start函数中是有this指针
void Thread::start()
{
	ThreadData * pdata = new ThreadData(_name, std::move(_cb));

	if(pthread_create(&_pthid, nullptr, threadFunc, pdata)) {
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
	ThreadData * pdata = static_cast<ThreadData*>(arg);
	if(pdata) {
		pdata->runInThread();
	}

	delete pdata;
	return nullptr;
}

void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid,nullptr);
		_isRunning = false;
	}
}


}// end of namesapce wd
