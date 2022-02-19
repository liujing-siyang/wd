 ///
 /// @file    TestTcpConnection.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 20:54:43
 ///
 
#include "Acceptor.hpp"
#include "TcpConnection.hpp"

#include <iostream>
using std::cout;
using std::endl;
 
void test0() 
{
	/* Acceptor acceptor("192.168.30.128", 8888); */ 
	wd::Acceptor acceptor("127.0.0.1", 8888);
	acceptor.ready();

	wd::TcpConnnection conn(acceptor.accept());

	cout << conn.toString() << " has connected!" << endl;
	cout << ">> recv msg frome client: " << conn.receive() << endl;
	conn.send("hello,client");
} 
 
int main(void)
{
	test0();
	return 0;
}
