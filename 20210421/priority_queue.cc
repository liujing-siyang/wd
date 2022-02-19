#include <math.h>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

//bool operator<(const T &lhs, const T &rhs);
void test()
{
    vector<int> number = {1, 4, 6, 6, 5, 2, 6, 7, 9, 8};
    /* priority_queue<int> pque(number.begin(), number.end());//迭代器的形式进行初始化 */

    //优先级队列底层使用的是堆排序，默认情况下std::less,默认
    //情况下就是一个大根堆。
    //当有新的元素插进来的时候，就会将堆顶元素与新插入的元素进行
    //比较，如果满足std::less（返回true），就会将新的元素去置换
    //老的堆顶，然后新的元素成为新的堆顶（优先级最高的）
    priority_queue<int> pque;

    for(size_t idx = 0; idx != number.size(); ++idx)
    {
        pque.push(number[idx]);//把vector中的数据插到优先级队列来
        cout << "优先级队列的顶部元素： " << pque.top() << endl;
    }

    while(!pque.empty())
    {
        cout << pque.top() << "  ";
        pque.pop();
    }
    cout << endl;
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
    /* friend struct Comapation; */
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
void test2()
{
    vector<Point> number = {
        Point(1, 2),
        Point(10, 2),
        Point(1, 3),
        Point(4, 2),
        Point(-11, 2),
        Point(12, 2),
    };
    /* priority_queue<Point> pque; */
    priority_queue<Point, vector<Point>, std::greater<Point>> pque;

    for(size_t idx = 0; idx != number.size(); ++idx)
    {
        pque.push(number[idx]);//把vector中的数据插到优先级队列来
        cout << "优先级队列的顶部元素： " << pque.top() << endl;
    }

    cout << endl << endl;
    while(!pque.empty())
    {
        cout << pque.top() << "  ";
        pque.pop();
    }
    cout << endl;

}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

