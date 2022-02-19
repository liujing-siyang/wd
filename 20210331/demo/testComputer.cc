#include "Computer.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    Computer com;
    com.setBrand("lenovo");
    com.setPrice(6000);
    com.print();

    return 0;
}
