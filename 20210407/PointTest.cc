#include <math.h>
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

    void print() const
    {
        cout << "(" << _ix
             <<"," << _iy
             << ")";
    }

    operator int()//类型转换函数
    {
        cout << "operator int()" << endl;
        return _ix + _iy;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test()
{
    Point pt1(1, 5);
    //没有重载输出流运算符本来会报错的，但由于类中有类型转换函数，所以将point转成int，才没有报错
    cout << "pt1 = " << pt1 << endl;//Point---->int
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

