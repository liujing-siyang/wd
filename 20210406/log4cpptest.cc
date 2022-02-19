#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/SimpleLayout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <iostream>

using std::cout;
using std::endl;

using namespace log4cpp;//一次将log4cpp中的实体全部引出来

void test()
{
    //日志的格式
    /* BasicLayout *pbl = new BasicLayout(); */
    /* SimpleLayout *psl = new SimpleLayout(); */
    PatternLayout *ppl = new PatternLayout();
    ppl->setConversionPattern("%d %c [%p] %m %n");

    //日志的目的地
    OstreamAppender *poa = new OstreamAppender("OstreamAppender1", &cout);
    poa->setLayout(ppl);
    
    //日志的记录器
    Category &root = Category::getRoot();
    root.addAppender(poa);
    //日志的优先级
    
    //只有当Category的优先级大于等于日志的优先级的时候，日志才会被记录下来
    /* root.setPriority(Priority::DEBUG); */
    root.setPriority(Priority::ERROR);

    root.emerg("This is emerg message");
    root.alert("This is alert message");
    root.error("This is error message");
    root.debug("This is debug message");

    //回收资源的
    Category::shutdown();
}

void test2()
{
    //日志的格式
    PatternLayout *ppl1 = new PatternLayout();
    ppl1->setConversionPattern("%d %c [%p] %m %n");

    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%d %c [%p] %m %n");

    //日志的目的地
    OstreamAppender *poa = new OstreamAppender("OstreamAppender1", &cout);
    poa->setLayout(ppl1);

    FileAppender *pfa = new FileAppender("FileAppender123", "wd.log");
    pfa->setLayout(ppl2);
    
    //日志的记录器
    Category &root = Category::getRoot();
    root.addAppender(poa);
    root.addAppender(pfa);
    root.setPriority(Priority::ERROR);

    root.emerg("This is emerg message");
    root.alert("This is alert message");
    root.error("This is error message");
    root.debug("This is debug message");

    //回收资源的
    Category::shutdown();
}

void test3()
{
    //日志的格式
    PatternLayout *ppl1 = new PatternLayout();
    ppl1->setConversionPattern("%d %c [%p] %m %n");

    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%d %c [%p] %m %n");

    //日志的目的地
    OstreamAppender *poa = new OstreamAppender("OstreamAppender1", &cout);
    poa->setLayout(ppl1);

    RollingFileAppender *prfa = new RollingFileAppender("RollingFileAppender123"
                                                        , "wd.log"
                                                        , 5 * 1024
                                                        , 3);
    prfa->setLayout(ppl2);
    
    //日志的记录器
    Category &root = Category::getRoot();
    root.addAppender(poa);
    root.addAppender(prfa);
    root.setPriority(Priority::ERROR);

    size_t idx = 0;
    while(idx < 300)
    {
        root.emerg("This is emerg message");
        root.alert("This is alert message");
        root.error("This is error message");
        root.debug("This is debug message");
        ++idx;

    }

    //回收资源的
    Category::shutdown();
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}

