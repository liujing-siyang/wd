#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void test()
{
    double x, y;
    cin >> x >> y;
    try
    {
        if(0 == y)
        {
            throw y;
        }

        cout << "(x/y) = " << x/y << endl;
    }
    catch(int e)
    {
        cout << "catch(int)" << endl;
    }
    catch(double d)
    {
        cout << "catch(double)" << endl;
    }
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

