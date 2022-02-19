 ///
 /// @file    errno.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-17 15:12:33
 ///

#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#include <iostream>
using std::cout;
using std::endl;

__thread int number = 0;
int gNumber = 1111;
 

void * threadFunc1(void * arg)
{

	//结论: errno并不是一个全局变量
	cout << "gNumber:" << gNumber << endl;
	number = 1;
	printf("1 pthread_t：%lu, &errno: %p, &number: %p, number:%d\n", 
			pthread_self(), &errno, &number, number);
	return nullptr;
}
 
void * threadFunc2(void * arg)
{
	number = 2;
	printf("2 pthread_t：%lu, &errno: %p, &number: %p, number:%d\n", 
			pthread_self(), &errno, &number, number);
	return nullptr;
}

void test0() 
{
	printf("main pthread_t：%lu, &errno: %p, &number: %p, number:%d\n", 
			pthread_self(), &errno, &number, number);
	pthread_t pthid1, pthid2;
	pthread_create(&pthid1, nullptr, threadFunc1, nullptr);
	pthread_create(&pthid2, nullptr, threadFunc2, nullptr);

	pthread_join(pthid1, nullptr);
	pthread_join(pthid2, nullptr);
} 

int main(void)
{
	test0();
	return 0;
}
