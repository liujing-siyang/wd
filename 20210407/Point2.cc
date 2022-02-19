#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class Point;//类的前向声明

class Line
{
public:
    //友元函数是可以进行重载
    float distance(const Point &lhs, const Point &rhs);
    float distance(Point &lhs, int ix, int iy);
};

class Point
{
    //2、友元之成员函数的形式
    friend float Line::distance(const Point &lhs, const Point &rhs);
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

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};


//1、友元之普通函数，自由函数，全局函数
float Line::distance(const Point &lhs, const Point &rhs)
{
    return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}

void test()
{
    /* Line line; */
    Point pt1(1, 5);
    Point pt2(4, 9);
    pt1.print();
    cout << "---->";
    pt2.print();
    /* cout << "之间的距离: " << line.distance(pt1, pt2) << endl; */
    cout << "之间的距离: " << Line().distance(pt1, pt2) << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

