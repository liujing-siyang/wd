#ifndef __MY_LOGGER_H__
#define __MY_LOGGER_H__
#include <log4cpp/Category.hh>

using namespace log4cpp;

class Mylogger
{
public:
    static Mylogger *getInstance();
    static void destroy();
    void warn(const char * msg);
    void error(const char * msg);
    void debug(const char * msg);
    void info(const char * msg);

private:
    Mylogger();
    ~Mylogger();
private:
    static Mylogger *_pInstance;
    Category &_root;
};

#define prefic(msg) string(__FILE__).append(" ").append(__FUNCTION__) \
                    .append(" ").append(std::to_string(__LINE__))\
                    .append(":").append(msg).c_str()

#define logError(msg) Mylogger::getInstance()->error(prefic(msg))
#define logInfo(msg) Mylogger::getInstance()->Info(prefic(msg))
#define logDebug(msg) Mylogger::getInstance()->debug(prefic(msg))
#define logWarn(msg) Mylogger::getInstance()->warn(prefic(msg))
#endif
