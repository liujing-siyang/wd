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

//_acceptor完成socket，bind和listen
//_loop将三个回调函数set,让后调用epoll的wait,处理连接的建立，消息的处理和连接的关闭，在Tcpconnect对象中执行回调函数（将任务加入任务队列）
#endif
