#include <iostream>

using std::cout;
using std::endl;

//1、不论以什么继承方式（public/protected/private），基类中的私有成员都不能在派生类中被访问
//2、不论以什么继承方式（public/protected/private），除了基类中的私有成员都不能在派生类中被访问,其他的都可以被访问
//3、对于派生类对象而言，只能访问public继承的基类中的public成员，其他都不能访问
class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    int getY() const
    {
        return _iy;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
protected:
    int _ix;
private://封装性
    int _iy;
};

class Point3D
: public Point
{
public:
    Point3D(int ix = 0, int iy = 0, int iz = 0)
    : Point(ix, iy)
    , _iz(iz)
    {
        cout << "Point3D(int = 0, int = 0, int = 0)" << endl;
    }

    void print()
    {
        cout << "(" << _ix //protected
             /* << ", " << _iy //error */
             << "," << getY() //public
             << "," << _iz //private
             << ")" << endl;
    }

    ~Point3D()
    {
        cout << "~Point3D()" << endl;
    }

private:
    int _iz;
};
int main(int argc, char **argv)
{
    Point3D pt3d(1, 2, 3);
    /* pt3d._ix = 10;//error */
    /* pt3d._iy = 10;//error */
    /* pt3d._iz = 10;//error */
    pt3d.getY();
    return 0;
}

