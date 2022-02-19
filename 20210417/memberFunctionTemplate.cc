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

    template <typename T = int>
    T getX()
    {
        return (T)_ix;
    }

    void print() const
    {
        cout << "(" <<_ix
            << ","  << _iy
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
    cout << "Hello world" << endl;
    return 0;
}

