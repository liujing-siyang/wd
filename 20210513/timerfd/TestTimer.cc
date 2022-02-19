 ///
 /// @file    TestTimer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-12 11:33:39
 ///
 
#include "Timer.hpp"
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
	Timer e(3, 6, process);
	Thread thread(std::bind(&Timer::start, &e));
	thread.start();

	sleep(20);
	e.stop();
	thread.join();

} 
 
int main(void)
{
	test0();
	return 0;
}
