 ///
 /// @file    TestTcpConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 20:54:43
 ///
 
#include "TcpServer.hpp"

#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

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
	
	Task task(msg);
	threadpool.addTask(std::bind(&Task::process, task));
}

void onClose(const TcpConnectionPtr & conn){
	cout << conn->toString() << " has closed!" << endl;
}

void test0() 
{
	/* Acceptor acceptor("192.168.30.128", 8888); */ 
	TcpServer server("127.0.0.1", 8888);
	server.setAllCallbacks(onConnection, onMessage, onClose);
	server.start();
} 
 
int main(void)
{
	test0();
	return 0;
}
