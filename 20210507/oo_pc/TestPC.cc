 ///
 /// @file    TestPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:50:53
 ///
 
#include "Producer.hpp"
#include "Consumer.hpp"
#include "TaskQueue.hpp"

#include <unistd.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;

using namespace wd;
 
void test0() 
{
	TaskQueue taskque(10);
	std::unique_ptr<Thread> producer1(new Producer(taskque));
	std::unique_ptr<Thread> producer2(new Producer(taskque));
	std::unique_ptr<Thread> consumer1(new Consumer(taskque));

	producer1->start();
	producer2->start();
	consumer1->start();

	producer1->join();
	producer2->join();
	consumer1->join();
} 
 
int main(void)
{
	test0();
	return 0;
}
