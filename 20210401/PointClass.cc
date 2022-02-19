#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    /* Point(int ix, int iy) */
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
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

class Line
{
public:
    Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
        cout << "Line(int = 0, int = 0, int = 0, int = 0)" << endl;
    }

    void printLine()
    {
        _pt1.print();
        cout << "---->";
        _pt2.print();
        cout << endl;
    }
private:
    Point _pt1;//子对象
    Point _pt2;
};
void test()
{
    Line line(1, 2, 3, 4);
    line.printLine();
}

int main(int argc, char **argv)
{
    test();

    return 0;
}

