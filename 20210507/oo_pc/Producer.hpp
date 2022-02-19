 ///
 /// @file    Producer.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 15:06:41
 ///
 
#ifndef __WD_PRODUCER_H__
#define __WD_PRODUCER_H__

#include "Thread.hpp"
#include "TaskQueue.hpp"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using std::cout;
using std::endl;

namespace wd
{
class Producer : public Thread
{
public:
	Producer(TaskQueue & taskque)
	: _taskQue(taskque)
	{}


private:
	void run()
	{
		::srand(::clock());
		int cnt = 20;
		while(cnt-- > 0) {
			int number = ::rand() % 100;
			_taskQue.push(number);
			cout << "> prodcer thread make a number:" << number << endl;
			sleep(1);
		}
	}

private:
	TaskQueue & _taskQue;
};


}//end of namespace wd

#endif
