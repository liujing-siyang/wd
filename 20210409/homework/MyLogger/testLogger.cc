#include "MyLogger.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string func(const char *msg)
{
    string s1 = string(__FILE__) +  string("  ")
                + string(__FUNCTION__) + string("  ")
                + string(std::to_string(__LINE__)) + msg;

    return s1;
}

void test()
{
    /* Mylogger::getInstance()->error("This is an error message"); */
    /* Mylogger::getInstance()->error(func("This is an error message").c_str()); */
    /* Mylogger::getInstance()->error(prefic("This is an error message")); */
    /* Mylogger::getInstance()->info(prefic("This is an info message")); */
    /* Mylogger::getInstance()->debug(prefic("This is an debug message")); */
    logError("This is an error message") ;
}

void test2()
{
    cout << __FILE__ << "    " <<  __FUNCTION__ 
         << "   "   <<  __LINE__ << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

