#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    //防止隐式转换
    explicit
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

int main(int argc, char **argv)
{
    Point pt1(1, 2);
    cout << "pt1 = ";
    pt1.print();

    cout << endl;
    Point pt2 = 4;//Point(4, 0)
    cout << "pt2 = ";
    pt2.print();

    return 0;
}

