#include <iostream>

using std::cout;
using std::endl;

class Data
{
public:
    Data(int data = 10)
    : _data(data)
    {
        cout << "Data(int = 10)" << endl;
    }

    int getData() const
    {
        return _data;
    }

    ~Data()
    {
        cout << "~Data()" << endl;
    }
private:
    ;
};

class SmartPointer
{
public:
    SmartPointer(Data *pdata)
    : _pdata(pdata)
    {
        cout << "SmartPointer(Data *)" << endl;
    }

    Data *operator->()
    {
        return _pdata;
    }

    Data &operator*()
    {
        return *_pdata;
    }

    ~SmartPointer()
    {
        cout << "~SmartPointer()" << endl;
        if(_pdata)
        {
            delete _pdata;
            _pdata = nullptr;
        }
    }
private:
    Data *_pdata;
};

class ThirdLayer
{
public:
    ThirdLayer(SmartPointer *psl)
    : _psl(psl)
    {
        cout << "ThirdLayer(SmartPointer *)" << endl;
    }

    SmartPointer &operator->()
    {
        return *_psl;
    }

    ~ThirdLayer()
    {
        cout << "~ThirdLayer()" << endl;
        if(_psl)
        {
            delete _psl;
            _psl = nullptr;
        }
    }
private:
    SmartPointer *_psl;
};
int main(int argc, char **argv)
{
    SmartPointer pointer(new Data());//智能指针的雏形
    pointer.operator->()->getData();//ok,原始调用形式
    cout << "pointer->getData() = " << pointer->getData() << endl;

    cout << "(*pointer).getData() = " << (*pointer).getData() << endl;
    pointer.operator*().getData();//ok

    cout << endl;
    ThirdLayer tl(new SmartPointer(new Data(20)));
    cout << "tl->getData = " << tl->getData() << endl;
    tl.operator->().operator->()->getData();//原始版本
    return 0;
}

