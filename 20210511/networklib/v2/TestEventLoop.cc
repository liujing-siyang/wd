 ///
 /// @file    TestTcpConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 20:54:43
 ///
 
#include "Acceptor.hpp"
#include "EventLoop.hpp"
#include "TcpConnection.hpp"

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
	conn->send(msg);
}

void onClose(const TcpConnectionPtr & conn){
	cout << conn->toString() << " has closed!" << endl;
}

void test0() 
{
	/* Acceptor acceptor("192.168.30.128", 8888); */ 
	Acceptor acceptor("127.0.0.1", 8888);
	acceptor.ready();

	EventLoop loop(acceptor);

	loop.setConnectionCallback(onConnection);
	loop.setMessageCallback(onMessage);
	loop.setCloseCallback(onClose);
	loop.loop();
} 
 
int main(void)
{
	test0();
	return 0;
}
