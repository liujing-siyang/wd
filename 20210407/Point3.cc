#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class Point;//类的前向声明

class Line
{
public:
    float distance(const Point &lhs, const Point &rhs);
    void setPoint(Point &rhs, int ix, int iy);
private:
    int _iz;
};

//友元是单向的，友元不具备传递性(A->B->C)，友元关系是不能被继承的
class Point
{
    //3、友元之友元类(一个类的所有成员函数都是另外一个类的友元)
    /* friend float Line::distance(const Point &lhs, const Point &rhs); */
    /* friend void Line::setPoint(Point &rhs, int ix, int iy); */
    friend class Line;
    /* friend Line; */
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

    void setLine(Line &line, int iz)
    {
        line._iz = iz;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};


float Line::distance(const Point &lhs, const Point &rhs)
{
    return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}

void Line::setPoint(Point &rhs, int ix, int iy)
{
    rhs._ix = ix;
    rhs._iy = iy;
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

