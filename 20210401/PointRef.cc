#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    , _ref(_ix)
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
             << ", " << _ref 
             << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
    int &_ref;//引用数据成员占一个指针大小的空间
};

void test()
{
    cout << "sizeof(Point) = " << sizeof(Point) << endl;

    cout << endl;
    Point pt(1, 2);//栈对象
    pt.print();
    pt.setX(200);
    pt.print();
}

int main(int argc, char **argv)
{
    test();

    return 0;
}

