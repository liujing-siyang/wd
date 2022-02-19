 ///
 /// @file    TestEventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-12 11:33:39
 ///
 
#include "Eventfd.hpp"
#include "Thread.hpp"


#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

void process()
{
	cout << " task is processing!" << endl;
}
 
void test0() 
{
	Eventfd e(process);
	Thread thread(std::bind(&Eventfd::start, &e));
	thread.start();
	int count = 20;
	while(count-- > 0) {
		e.wakeup();//主线程通知子线程执行任务
		sleep(1);
	}

	e.stop();
	thread.join();

} 
 
int main(void)
{
	test0();
	return 0;
}
