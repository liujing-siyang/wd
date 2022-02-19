 ///
 /// @file    Socket.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 16:12:27
 ///
 
#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__

#include "Noncopyable.hpp"


namespace wd
{

class Socket
: Noncopyable
{
public:
	Socket();
	explicit Socket(int fd);//只带一个关键字的情况考虑隐式转换
	~Socket();

	int fd() const {	return _fd;	}	

	void shutdownWrite();//主动断开连接，关闭写端

private:
	int _fd;
};

}//end of namespace wd

#endif
