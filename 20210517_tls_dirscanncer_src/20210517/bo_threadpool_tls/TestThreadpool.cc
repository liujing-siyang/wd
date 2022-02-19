 ///
 /// @file    TestPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-06 11:50:53
 ///
 
#include "Threadpool.hpp"

#include <unistd.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;

using namespace wd;

class Mytask 
{
public:
	void process()
	{
		srand(clock());
		int number = rand() % 100;
		cout << ">>bo_threadpool. number:" << number  
			 << "sub thread name: " << wd::current_thread::name << endl;
	}
};

 
void test0() 
{
	unique_ptr<Mytask> ptask(new Mytask);
	Threadpool threadpool(4, 10);
	threadpool.start();

	int cnt = 20;
	while(cnt-- > 0) {
		threadpool.addTask(std::bind(&Mytask::process, ptask.get()));
		cout << "cnt:" << cnt << endl;
	}



	threadpool.stop();
} 
 
int main(void)
{
	test0();
	return 0;
}
