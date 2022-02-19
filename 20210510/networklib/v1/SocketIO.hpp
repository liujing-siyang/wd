 ///
 /// @file    SocketIO.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 17:05:33
 ///
 
#ifndef __WD_SOCKETIO_H__
#define __WD_SOCKETIO_H__


namespace wd
{
//负责数据的收发
class SocketIO
{
public:
	SocketIO(int fd): _fd(fd) {}

	int readn(char * buff, int len);
	int readline(char * buff, int maxlen);
	int writen(const char * buff, int len);
private:

private:
	int _fd;
};

}//end of namespace wd

#endif
