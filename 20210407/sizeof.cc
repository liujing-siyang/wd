#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    int number = 10;

    printf("sizeof(number) = %lu\n", sizeof(number));
    printf("sizeof number = %lu\n", sizeof number);
    return 0;
}

