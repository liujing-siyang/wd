#include <pthread.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
//使用的线程相关的函数，编译时加上-lpthread
//4、pthread_once + atexit(平台相关)
class Singleton
{
public:
    //多线程环境下，安全
    static Singleton *getInstance()
    {
        //在pthread_once第一个参数被设置成PTHREAD_ONCE_INIT这个宏之后
        //在多线程的情况下，第二个参数就只会执行一次,静态的成员函数只能访问静态的数据成员和静态的成员函数
        pthread_once(&_once, init);

        return _pInstance;
    }

    static void init()
    {
        _pInstance = new Singleton();
        atexit(destroy);
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }

    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
private:
    static Singleton *_pInstance;
    static pthread_once_t _once;
};
Singleton *Singleton::_pInstance = nullptr;//饱汉（懒汉）模式
/* Singleton *Singleton::_pInstance = Singleton::getInstance();//饿汉模式 */
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(int argc, char **argv)
{
    //多线程执行两次
    Singleton::getInstance();
    Singleton::getInstance();
    return 0;
}

