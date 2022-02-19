 ///
 /// @file    TestThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:50:53
 ///
 
#include "Thread.hpp"

#include <unistd.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;

class MyThread
: public wd::Thread
{
	void run()
	{
		while(1) {
			cout << "Thread is running!" << endl;
			sleep(1);
		}
	}
};
 
void test0() 
{
	std::unique_ptr<wd::Thread> mythread(new MyThread());
	mythread->start();
	mythread->join();
} 
 
int main(void)
{
	test0();
	return 0;
}
