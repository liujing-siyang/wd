#include <iostream>

using std::cout;
using std::endl;

//2、内部类 + 静态数据成员
class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
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
    class AutoRelease
    {
    public:
        AutoRelease()
        {
            cout << "AutoRelease()" << endl;
        }
    
        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;
            if(_pInstance)
            {
                delete _pInstance;
                _pInstance = nullptr;
            }
    
        }
    };
private:
    static Singleton *_pInstance;
    static AutoRelease _auto;
};
/* Singleton *Singleton::_pInstance = nullptr; */
Singleton *Singleton::_pInstance = getInstance();
Singleton::AutoRelease Singleton::_auto;

int main(int argc, char **argv)
{
    Singleton::getInstance();
    /* Singleton::destroy(); */
    /* Singleton::AutoRelease ato; */
    return 0;
}

