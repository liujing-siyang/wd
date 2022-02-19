#include "Mylogger.h"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{
Mylogger * Mylogger::_pInstance = nullptr;

Mylogger * Mylogger::getInstance() 
{
	if(nullptr == _pInstance)
    {
		_pInstance = new Mylogger();
	}
	return _pInstance;
}

void Mylogger::destroy()
{
	if(_pInstance) 
    {
		delete _pInstance;
        _pInstance = nullptr;
	}
}

Mylogger::Mylogger()
: _mycat(Category::getRoot().getInstance("MyCategory"))
{
	PatternLayout * ppl1 = new PatternLayout();
	ppl1->setConversionPattern("%d %c [%p] %m %n");

	PatternLayout * ppl2 = new PatternLayout();
	ppl2->setConversionPattern("%d %c [%p] %m %n");

	OstreamAppender *poa = new OstreamAppender("OstreamAppender", &cout);
	poa->setLayout(ppl1);

	FileAppender * pfa = new FileAppender("FileAppender", "wd.log");
	pfa->setLayout(ppl2);

	_mycat.addAppender(poa);
	_mycat.addAppender(pfa);
    _mycat.setPriority(Priority::DEBUG);
	cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger() 
{
	cout << "~Mylogger()" << endl;
	log4cpp::Category::shutdown();
}

#if 1
void Mylogger::warn(const char *msg)
{
	_mycat.warn(msg);
}

void Mylogger::error(const char *msg)
{
	_mycat.error(msg);
}

void Mylogger::info(const char *msg)
{
	_mycat.info(msg);
}

void Mylogger::debug(const char *msg)
{
	_mycat.debug(msg);
}
#endif
void Mylogger::setPriority(Priority p)
{
	switch(p)
	{
	case WARN:
		_mycat.setPriority(Priority::WARN);
		break;
	case ERROR:
		_mycat.setPriority(Priority::ERROR);
		break;
	case INFO:
		_mycat.setPriority(Priority::INFO);
		break;
	case DEBUG:
		_mycat.setPriority(Priority::DEBUG);
		break;
	}
}


}//end of namespace wd
