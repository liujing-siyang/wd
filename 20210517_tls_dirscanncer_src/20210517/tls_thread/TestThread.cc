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

class MyTask
{
public:
	void process()
	{
		cout << "thread_name:" << wd::current_thread::name << endl;
		int cnt = 3;
		while(cnt-- > 0) {
			cout << "Thread is running!" << endl;
			sleep(1);
		}
	}
private:
	/* string _name; */
};

 
void test0() 
{
	MyTask task;
	//Mytask::process(&task);
	//对于成员函数而言，当注册给function之后，要注意，如果传递对象的指针，对象生命周期
	//要大于回调函数执行完毕的时机; 如果不是，那当执行回调函数时，对象已经销毁，
	//此时再去执行回调函数，就有出错的风险，而且是不确定的
	/* std::function<void()> f = std::bind(&MyTask::process, &task); */
	//f();
	//可以注册成员函数
	/* std::unique_ptr<wd::Thread> mythread(new wd::Thread(std::move(f))); */
	std::unique_ptr<wd::Thread> mythread(new wd::Thread(
		std::bind(&MyTask::process, &task), "1号线程"));

	cout << "main thread name:" << wd::current_thread::name << endl;
	//也可以注册普通函数, 基于对象的写法会更灵活
	/* std::unique_ptr<wd::Thread> mythread(new wd::Thread(process)); */
	mythread->start();
	mythread->join();
} 
 
int main(void)
{
	test0();
	return 0;
}
