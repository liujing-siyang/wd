#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }

    void print()
    {
        cout << "(" << _ix 
             << ", " << _iy 
             << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

template <typename T>//这里相当于auto_ptr的源码实现
class RAII
{
public:
    //构造时初始化资源
    RAII(T *data)
    : _data(data)
    {
        cout << "RAII(T *)" << endl;
    }

    //提供若干访问资源的方法
    T *operator->()
    {
        return _data;
    }

    T &operator*()
    {
        return *_data;
    }

    T *get()
    {
        return _data;
    }

    void reset(T *data)
    {
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }
    //在析构的时候释放资源
    ~RAII()
    {
        cout << "~RAII()" << endl;
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }
    }
    //不允许复制或者赋值
    RAII(const RAII &rhs) = delete;//C++11提出来的
    RAII &operator=(const RAII &rhs) = delete;
private:
    T *_data;

};
int main(int argc, char **argv)
{
    RAII<Point> pt(new Point(1, 2));//pt栈对象
    /* pt.operator->()->print(); */
    pt->print();

    /* RAII<Point> pt2 = pt;//error */
    return 0;
}

