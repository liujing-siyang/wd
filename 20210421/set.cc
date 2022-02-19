#include <math.h>
#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::set;
using std::vector;

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
    set<int> number = {1, 2, 3, 5, 9, 4, 5, 3, 2, 5};
    /* set<int, std::less<int>> number = {1, 2, 3, 5, 9, 4, 5, 3, 2, 5}; */
    /* set<int, std::greater<int>> number = {1, 2, 3, 5, 9, 4, 5, 3, 2, 5}; */
    display(number);

    cout << endl << "set的查找" << endl;
    size_t cnt1 = number.count(5);
    size_t cnt2 = number.count(10);
    cout << "cnt1 = " << cnt1 << endl;
    cout << "cnt2 = " << cnt2 << endl;

    cout << endl;
    set<int>::iterator it = number.find(5);
    /* auto it2 = number.find(5); */
    if(it == number.end())
    {
        cout << "该值不存在set中" << endl;
    }
    else
    {
        cout << "该值存在set中" << *it << endl;
    }

    cout << endl << "在set中进行插入" << endl;
    std::pair<set<int>::iterator, bool> ret = number.insert(5);
    if(ret.second)
    {
        cout << "set中不存在该值，可以插入" 
              << *ret.first << endl; 
    }
    else
    {
        cout << "该值存在set中，无法插入" << endl;
    }
    display(number);

    cout << endl;
    vector<int> vec{1, 3, 7, 9, 34, 12, 14};
    number.insert(vec.begin(), vec.end());
    display(number);

    cout << endl << "set的删除" << endl;
    it = number.begin();
    ++it;
    ++it;
    number.erase(it);
    display(number);

    cout << endl;
    it = number.begin();
    /* *it = 10;//error,不支持修改，保护数据 */

    /* number[0];//error,不支持下标访问 */
}

struct Comapation;//类的前向声明

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

    int getX() const
    {
        return _ix;
    }

    int getY() const
    {
        return _iy;
    }

    void print()
    {
        cout << "(" << _ix 
             << ", " << _iy 
             << ")" << endl;
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

bool operator<(const Point &lhs, const Point &rhs)
{
    cout << "bool operator<(const Point &, const Point &)" << endl;
    if(lhs.getDistance() < rhs.getDistance())
    {
        return true;
    }
    else if(lhs.getDistance() == rhs.getDistance())
    {
        if(lhs._ix < rhs._ix)
        {
            return true;
        }
        else if(lhs._ix == rhs._ix)
        {
            if(lhs._iy < rhs._iy)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool operator>(const Point &lhs, const Point &rhs)
{
    cout << "bool operator>(const Point &, const Point &)" << endl;
    if(lhs.getDistance() > rhs.getDistance())
    {
        return true;
    }
    else if(lhs.getDistance() == rhs.getDistance())
    {
        if(lhs._ix > rhs._ix)
        {
            return true;
        }
        else if(lhs._ix == rhs._ix)
        {
            if(lhs._iy > rhs._iy)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

struct Comapation
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        cout << "bool operator()(const Point &, const Point &) const" << endl;
        if(lhs.getDistance() > rhs.getDistance())
        {
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance())
        {
            if(lhs._ix > rhs._ix)
            {
                return true;
            }
            else if(lhs._ix == rhs._ix)
            {
                if(lhs._iy > rhs._iy)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

    }

};
namespace  std
{
template <>
struct greater<Point>
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        cout << "bool operator()(const Point &, const Point &) const" << endl;
        if(lhs.getDistance() > rhs.getDistance())
        {
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance())
        {
            if(lhs.getX() > rhs.getX())
            {
                return true;
            }
            else if(lhs.getX() == rhs.getX())
            {
                if(lhs.getY() > rhs.getY())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

    }

};
};
void test2()
{
    /* set<Point> number = { */
    set<Point, std::less<Point>> number = {
    /* set<Point, std::greater<Point>> number = { */
    /* set<Point, Comapation> number = { */
        Point(1, 2),
        Point(-2, 3),
        Point(0, 3),
        Point(-6, 3),
        Point(6, 3),
        Point(6, 3),
    };
    display(number);
}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

