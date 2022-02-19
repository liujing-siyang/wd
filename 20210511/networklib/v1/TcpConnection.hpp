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

using std::string;

namespace wd
{
	
class TcpConnnection : Noncopyable
{
public:
	TcpConnnection(int fd);

	string receive();
	void send(const string & msg);

	string toString() const;
private:
	InetAddress getLocalAddr();
	InetAddress getPeerAddr();
private:
	Socket _sock;
	SocketIO _sockIO;
	InetAddress _localAddr;
	InetAddress _peerAddr;
	bool _isShutdownWrite;
};



}//end of namespace wd

#endif
