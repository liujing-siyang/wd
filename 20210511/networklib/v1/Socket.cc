 ///
 /// @file    Socket.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 16:14:21
 ///

#include "Socket.hpp"

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>


namespace wd
{

Socket::Socket()
{
	_fd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(_fd < 0) {
		perror("socket");
	}
}

Socket::Socket(int fd)
: _fd(fd)
{}

Socket::~Socket()
{
	close(_fd);
}

void Socket::shutdownWrite()
{
	shutdown(_fd, SHUT_WR);
}
 
}//end of namespace wd
