 ///
 /// @file    TestTcpConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 20:54:43
 ///
 
#include "TcpServer.hpp"
#include "Threadpool.hpp"
#include "Thread.hpp"

#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using namespace wd;

int str2int(const string & str)
{
	int idx = -1;
	std::istringstream iss(str);
	iss >> idx;
	return idx;
}


class MyTask
{
public:
	MyTask(const string &msg, const TcpConnectionPtr & conn)
	: _msg(msg)
	, _conn(conn)
	{}

	//process方法在一个子线程(计算线程)中运行
	void process()
	{
		cout << "Mytask::process is running！" << endl;
		//decode
		//compute
		//encode
		
		/* pthread_t pthid = pthread_self(); */
		//1. 先从cache中查询结果
		//这个idx怎么获取呢？方案: 通过TLS(线程局部存储)来jjie解决
		//
		//2. process方法的执行也不能确定是哪一个子线程
		//
		LRUCache & cache = 
			CacheManager::getInstance()->getCache(str2int(wd::current_thread::name));

		//2. 如果缓存中没有结果，就继续走查询模块
		
		_conn->sendInLoop(_msg);//意味着TcpConnection对象知道EventLoop对象的存在
	}

private:
	string _msg;
	TcpConnectionPtr _conn;
};

//对于全局变量，尽量少使用，甚至不使用
Threadpool * gThreadpool = nullptr;

void onConnection(const TcpConnectionPtr & conn) {
	cout << conn->toString() << " has connected!" << endl;
}

void onMessage(const TcpConnectionPtr & conn) {
	string msg = conn->receive();
	cout << ">> recv: " << msg;
	//decode
	//compute
	//endcode
	//conn->send(msg);
	
	//将业务逻辑的处理交给线程池执行
	MyTask task(msg, conn);
	//使用的线程池是一个基于对象的线程池
	gThreadpool->addTask(std::bind(&MyTask::process, task));
}

void onClose(const TcpConnectionPtr & conn){
	cout << conn->toString() << " has closed!" << endl;
}



class EchoServer
{
public:
	EchoServer(const string & ip, unsigned short port)
	: _threadpool(4, 100)
	, _server(ip, port)
	{}

	void start()
	{
		using namespace std::placeholders;
		_threadpool.start();
		_server.setAllCallbacks(
				std::bind(&EchoServer::onConnection, this, _1),
				std::bind(&EchoServer::onMessage, this, _1),
				std::bind(&EchoServer::onClose, this, _1));

		_server.start();
	}

	void stop()
	{
		_server.stop();
		_threadpool.stop();
	}

	void onConnection(const TcpConnectionPtr & conn)
	{
		cout << conn->toString() << " has connected!\n";
	}

	void onMessage(const TcpConnectionPtr & conn)
	{
		string msg = conn->receive();
		cout << "EchoServer::onMessage() has called\n";
		
		MyTask task(msg, conn);
		_threadpool.addTask(std::bind(&MyTask::process, &task));
	}
	
	void onClose(const TcpConnectionPtr & conn)
	{
		cout << conn->toString() << " has closed!\n";
	}

private:
	Threadpool _threadpool;
	TcpServer _server;
};

void test0() 
{
	//配置文件做成单例模式
	Threadpool threadpool(4, 100);
	threadpool.start();
	gThreadpool = &threadpool;

	TcpServer server("127.0.0.1", 8888);
	server.setAllCallbacks(onConnection, onMessage, onClose);
	server.start();
} 

void test1()
{
	EchoServer echo("127.0.0.1", 8888);
	echo.start();
}
 
int main(void)
{
	test1();
	return 0;
}
