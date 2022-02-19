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

//默认的继承方式是私有的
class Point3D
: protected Point
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
             << "," << getY() //protected
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

class Point4D
: protected Point3D
{
public:
    void show()
    {
        cout << "(" << _ix //protected
             /* << ", " << _iy //error */
             << "," << getY() //protected
             /* << "," << _iz //perror */
             << ", " << _ia << endl
             << ")" << endl;
    }

private:
    int _ia;
};
int main(int argc, char **argv)
{
    Point3D pt3d(1, 2, 3);
    /* pt3d._ix = 10;//error */
    /* pt3d._iy = 10;//error */
    /* pt3d._iz = 10;//error */
    /* pt3d.getY(); */
    return 0;
}

