 ///
 /// @file    EventLoop.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-11 15:49:19
 ///

#ifndef __WD_EVENTLOOP_H__
#define __WD_EVENTLOOP_H__

#include <sys/epoll.h>

#include <vector>
#include <map>
#include <memory>
#include <functional>
namespace wd
{

class Acceptor;
class TcpConnection;

using TcpConnectionPtr = std::shared_ptr<TcpConnection>;

class EventLoop
{
	using EventList = std::vector<struct epoll_event>;
	using TcpConnsMap = std::map<int, TcpConnectionPtr>;
	using TcpConnectionCallback = std::function<void(const TcpConnectionPtr&)>;
public:
	EventLoop(Acceptor &);
	~EventLoop();

	void loop();
	void unloop();

	void setConnectionCallback(TcpConnectionCallback && cb);
	void setMessageCallback(TcpConnectionCallback && cb);
	void setCloseCallback(TcpConnectionCallback && cb);
private:
	void waitEpollfd();
	void handleNewConnection();
	void handleMessage(int);

	int createEpollfd();
	void addEpollReadFd(int fd);
	void delEpollReadFd(int fd);


private:

	int         _efd;
	Acceptor &  _acceptor;
	bool        _isLooping;
	EventList   _evtList;
	TcpConnsMap _conns;

	//定义回调函数，挖空
	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;

	
};

}//end of namespace wd

#endif
