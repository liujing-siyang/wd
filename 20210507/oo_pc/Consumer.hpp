 ///
 /// @file    Consumer.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 15:13:53
 ///
 
#ifndef _WD_CONSUMER_H__
#define _WD_CONSUMER_H__

#include "TaskQueue.hpp"
#include "Thread.hpp"

#include <unistd.h>	

#include <iostream>

using std::cout;
using std::endl;

namespace wd
{
class Consumer: public Thread
{
public:
	Consumer(TaskQueue & taskque)
	: _taskQue(taskque)
	{}


private:
	void run()
	{
		int cnt = 20;
		while(1) {
			int number = _taskQue.pop();
			cout << "> consumer thread  get a number:" << number << endl;
			sleep(1);
		}
	}

private:
	TaskQueue & _taskQue;
};

}//end of namespace wd

#endif
