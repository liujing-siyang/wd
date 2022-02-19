#include "Line.h"
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImpl
{
public:
    LineImpl(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
        cout << "LineImpl(int, int, int, int)" << endl;
    }

    void printImpl() const
    {
        _pt1.print();
        cout << "--->";
        _pt2.print();
        cout << endl;
    }

    ~LineImpl()
    {
        cout << "~LineImpl()" << endl;
    }
private:
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
                 << ", " << _iy
                 << ")";
        }

        ~Point()
        {
            cout <<"~Point()" << endl;
        }
    private:
        int _ix;
        int _iy;
    };

private:
    Point _pt1;
    Point _pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
    cout << "Line(int, int, int, int)" << endl;
}

void Line::printLine() const
{
    _pimpl->printImpl();
}

Line::~Line()
{
    cout << "~Line()" << endl;
    if(_pimpl)
    {
        delete  _pimpl;
        _pimpl = nullptr;
    }
}
