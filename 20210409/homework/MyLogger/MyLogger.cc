#include "MyLogger.h"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

#include <iostream>

using std::cout;
using std::endl;

Mylogger *Mylogger::_pInstance = nullptr;

Mylogger *Mylogger::getInstance()
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
void Mylogger::warn(const char * msg)
{
    _root.warn(msg);
}
void Mylogger::error(const char * msg)
{
    _root.error(msg);
}
void Mylogger::debug(const char * msg)
{
    _root.debug(msg);
}
void Mylogger::info(const char * msg)
{
    _root.info(msg);
}

Mylogger::Mylogger()
: _root(Category::getRoot().getInstance("Mycat"))
{
    cout << "Mylogger()" << endl;

    //日志的格式
    PatternLayout *ppl1 = new PatternLayout();
    ppl1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%d %c [%p] %m%n");

    //日志的目的地
    OstreamAppender *poa = new OstreamAppender("OstreamAppender", &cout);
    poa->setLayout(ppl1);

    FileAppender *pfa = new FileAppender("FileAppender", "wd.log");
    pfa->setLayout(ppl2);

    _root.addAppender(poa);
    _root.addAppender(pfa);
    _root.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    cout << "~Mylogger()" << endl;
    Category::shutdown();
}

