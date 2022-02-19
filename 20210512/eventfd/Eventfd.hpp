 ///
 /// @file    Eventfd.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-12 11:19:06
 ///
 

#ifndef __WD_EVENTFD_H__
#define __WD_EVENTFD_H__
#include <functional>

namespace wd
{

class Eventfd
{
	using EventCallback = std::function<void()>;
public:
	Eventfd(EventCallback && cb);

	void start();
	void stop();
	void wakeup();
private:
	void handleRead();
	int createEventfd();

private:
	int _evfd;
	EventCallback _cb;//void process()
	bool _isStarted;
};

}//end of namespace wd


#endif
