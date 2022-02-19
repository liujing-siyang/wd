#include <iostream>

using std::cout;
using std::endl;

printf("hello\n");

namespace wd
{
int number = 10;
}

namespace wd
{
number = 20;
}
int main(int argc, char **argv)
{
    cout << "Hello world" << endl;
    return 0;
}

