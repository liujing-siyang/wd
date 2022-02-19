 ///
 /// @file    Thread.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:30:46
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include <pthread.h>

#include <string>
#include <functional>
using std::function;
using std::string;

namespace wd
{

namespace current_thread
{
extern __thread const char * name;
}// end of namespace current_thread

class Thread
{
public:
	using ThreadCallback = function<void()>;

	Thread(ThreadCallback && cb, const string & name = std::string())
	: _pthid(0)
	, _name(name)
	, _isRunning(false)
	, _cb(std::move(cb))  //注册回调函数
	{}

	~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void*);

private:
	pthread_t _pthid;
	std::string _name;
	bool _isRunning;
	ThreadCallback _cb;
};

}//end of nanmespace wd

#endif
