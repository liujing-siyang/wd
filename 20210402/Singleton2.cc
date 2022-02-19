#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//设计要求: 一个类只能创建一个对象

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

    void print()
    {

    }
/* private: */
    Singleton()
    {

        cout << "Singleton()" << endl;
    }
/* private: */
    static Singleton *_pInsatnce ;
};

/* Singleton *Singleton::_pInsatnce = nullptr; */
Singleton *Singleton::_pInsatnce = getInstance();
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

     Singleton *ps3 = (Singleton *)malloc(sizeof(Singleton));
     memcpy(ps3, ps1, sizeof(10));
     ps3->print();
     Singleton::_pInsatnce = nullptr;
    return 0;
}

