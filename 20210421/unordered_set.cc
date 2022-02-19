#include <math.h>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

template <typename Container>
void display(const Container &c)
{
    for(auto &elem : c)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test()
{
    //无序
    //key值唯一
    unordered_set<int> number = { 4, 6, 8, 3, 5, 6, 1, 2, 5, 6};
    display(number);
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        /* cout << "Point(int, int)" << endl; */
    }

    float getDistance() const
    {
        return hypot(_ix, _iy);
    }

    void print()
    {
        cout << "(" << _ix 
             << ", " << _iy 
             << ")" << endl;
    }

    int getX() const
    {
        return _ix;
    }

    int getY() const
    {
        return _iy;
    }

    ~Point()
    {
        /* cout << "~Point()" << endl; */
    }

    friend bool operator<(const Point &lhs, const Point &rhs);
    friend bool operator>(const Point &lhs, const Point &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
    friend struct Comapation;
    /* friend Comapation; */
private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix 
       << ", " << rhs._iy 
       << ")";

    return os;
}

//标准命名空间进行扩展
namespace std
{
//模板的特化
template <>
struct hash<Point>
{
    size_t operator()(const Point &rhs) const
    {
        return (rhs.getX() << 1 ) ^ (rhs.getY() << 2);
    }
};//end of struct

}//end of namespace std

struct HasherPoint
{
    size_t operator()(const Point &rhs) const
    {
        cout << "struct HasherPoint..." << endl;
        return (rhs.getX() << 1 ) ^ (rhs.getY() << 2);
    }

};

//等价于实现std::equal_to
bool operator==(const Point &lhs, const Point &rhs)
{
    return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}

//std::equal_to针对Point的特化版本
namespace std
{
//模板的特化
template <>
struct equal_to<Point>
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }
};//end of struct

}//end of namespace std

//自定义函数对象实现std::equal_to的功能
struct EqualToPoint
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }

};
void test2()
{
    /* unordered_set<Point> number = { */
    unordered_set<Point, HasherPoint> number = {
        Point(1, 2),
        Point(-1, -2),
        Point(3, 22),
        Point(4, 2),
        Point(1, 19),
        Point(4, 2),
    };
    display(number);
}

int main(int argc, char **argv)
{
    test2();
    return 0;
}

