 ///
 /// @file    Timer.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-12 11:19:06
 ///
 

#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__
#include <functional>

namespace wd
{

class Timer
{
	using TimerCallback = std::function<void()>;
public:
	Timer(int initsec, int periodicsec,  TimerCallback && cb);

	void start();
	void stop();
private:
	void handleRead();
	int createTimerfd();
	void setTimerfd(int initsec, int periodicsec);

private:
	int _timerfd;
	int _initTime;
	int _periodicTime;
	TimerCallback _cb;
	bool _isStarted;
};

}//end of namespace wd


#endif
