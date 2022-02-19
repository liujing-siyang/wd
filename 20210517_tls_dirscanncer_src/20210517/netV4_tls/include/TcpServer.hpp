 ///
 /// @file    TcpServer.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-11 17:51:53
 ///

#ifndef __WD_TCPSERVER_H__
#define __WD_TCPSERVER_H__

#include "Acceptor.hpp"
#include "EventLoop.hpp"
#include "TcpConnection.hpp"

namespace wd
{

class TcpServer
{
public:
	TcpServer(const string & ip, unsigned short port)
	: _acceptor(ip, port)
	, _loop(_acceptor)
	{}

	void start()
	{
		_acceptor.ready();
		_loop.loop();
	}

	void stop()
	{
		_loop.unloop();
	}

	void setAllCallbacks(TcpConnectionCallback && onConnection,
			TcpConnectionCallback && onMessage,
			TcpConnectionCallback && onClose)
	{
		_loop.setConnectionCallback(std::move(onConnection));
		_loop.setMessageCallback(std::move(onMessage));
		_loop.setCloseCallback(std::move(onClose));
	}

private:
	Acceptor _acceptor;
	EventLoop _loop;
};

}//end of namespace wd


#endif
