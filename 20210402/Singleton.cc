#include <iostream>

using std::cout;
using std::endl;

//设计要求: 一个类只能创建一个对象
//适用的场景：全局唯一的对象，字典库、词典库、日志记录器
class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(nullptr == _pInsatnce)
        {
            _pInsatnce = new Singleton();
        }
        return _pInsatnce;
    }

    static void destroy()
    {
        if(_pInsatnce)
        {
            delete _pInsatnce;
            _pInsatnce = nullptr;
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
    static Singleton *_pInsatnce;
};

Singleton *Singleton::_pInsatnce = nullptr;
/* Singleton gS1;//全局对象,error */
/* Singleton gS2;//全局对象,error */

int main(int argc, char **argv)
{
    /* Singleton s1;//栈对象,error */
    /* Singleton s2;//error */
    /* Singleton *ps1 = new Singleton();//error */
     Singleton *ps1 = Singleton::getInstance();
     Singleton *ps2 = Singleton::getInstance();
     cout << "ps1 = " << ps1 << endl
          << "ps2 = " << ps2 << endl;
    /* delete ps1; */
    /* delete ps2; */
     Singleton::destroy();
     Singleton::destroy();
     Singleton::destroy();
     Singleton::destroy();
     Singleton::destroy();
    return 0;
}

