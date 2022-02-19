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
        cout << "Point(int = 0, int = 0)" << endl;
    }

    void setX(int ix)
    {
        _ix = ix;//赋值
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
    const int _ix;
    const int _iy;
};

void test()
{
    Point pt(1, 2);//栈对象
    pt.print();
}

int main(int argc, char **argv)
{
    test();

    return 0;
}

