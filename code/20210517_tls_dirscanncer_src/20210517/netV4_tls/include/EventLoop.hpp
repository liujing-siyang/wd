 ///
 /// @file    EventLoop.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-11 15:49:19
 ///

#ifndef __WD_EVENTLOOP_H__
#define __WD_EVENTLOOP_H__

#include "MutexLock.hpp"

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
using TcpConnectionCallback = std::function<void(const TcpConnectionPtr&)>;

class EventLoop
{
	using EventList = std::vector<struct epoll_event>;
	using TcpConnsMap = std::map<int, TcpConnectionPtr>;
	using Functor = std::function<void()>;
public:
	EventLoop(Acceptor &);
	~EventLoop();

	void loop();
	void unloop();
	void runInLoop(Functor && cb);

	void setConnectionCallback(TcpConnectionCallback && cb);
	void setMessageCallback(TcpConnectionCallback && cb);
	void setCloseCallback(TcpConnectionCallback && cb);
private:
	void waitEpollfd();
	void handleNewConnection();
	void handleMessage(int);
	void doPendingFunctors();

	int createEpollfd();
	void addEpollReadFd(int fd);
	void delEpollReadFd(int fd);

	int createEventfd();
	void wakeup();
	void handleRead();

private:
	int         _efd;
	int		    _evfd;
	Acceptor &  _acceptor;
	bool        _isLooping;
	EventList   _evtList;
	TcpConnsMap _conns;

	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;
	std::vector<Functor>  _pendingFunctors;
	MutexLock             _mutex;
};

}//end of namespace wd

#endif
