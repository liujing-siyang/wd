 ///
 /// @file    TcpConnection.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 16:39:19
 ///
 
#ifndef __WD_TCPCONNECTION_H__
#define __WD_TCPCONNECTION_H__

#include "Noncopyable.hpp"
#include "Socket.hpp"
#include "SocketIO.hpp"
#include "InetAddress.hpp"

#include <string>
#include <memory>
#include <functional>

using std::string;

namespace wd
{
	
class TcpConnection 
: Noncopyable
, public std::enable_shared_from_this<TcpConnection>//通过本对象的this指针获取指向本对象的智能指针
{
	using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
	using TcpConnectionCallback = std::function<void(const TcpConnectionPtr&)>;
public:
	TcpConnection(int fd);

	string receive();
	void send(const string & msg);
	bool isClosed() const;

	string toString() const;

	void setConnectionCallback(const TcpConnectionCallback & cb);
	void setMessageCallback(const TcpConnectionCallback & cb);
	void setCloseCallback(const TcpConnectionCallback & cb);

	void handleConnectionCallback();
	void handleMessageCallback();
	void handleCloseCallback();

private:
	InetAddress getLocalAddr();
	InetAddress getPeerAddr();
private:
	Socket _sock;
	SocketIO _sockIO;
	InetAddress _localAddr;
	InetAddress _peerAddr;
	bool _isShutdownWrite;

	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;

};



}//end of namespace wd

#endif
