#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//3、atexit + 饿汉模式
class Singleton
{
public:
    //多线程环境下，不安全
    //开始为nullptr == _pInstance，多线程就会new多次，同时也注册多次destroy
    //在destory中开始_pInstance不为空会执行delete，但后续的其它线程进入destroy时
    //会因为_pInstance在前一个线程已经置为空而不会去delete
    //所以我们可以改成饱汉模式，让_pInstance一开始就有值
    static Singleton *getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
            atexit(destroy);
        }

        return _pInstance;
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
};
/* Singleton *Singleton::_pInstance = nullptr;//饱汉（懒汉）模式 */
Singleton *Singleton::_pInstance = Singleton::getInstance();//饿汉模式

int main(int argc, char **argv)
{
    //多线程执行两次
    Singleton::getInstance();
    Singleton::getInstance();
    return 0;
}

