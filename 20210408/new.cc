#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    int *pInt = new int(10);
    cout << "*pInt = " << *pInt << endl;

    delete pInt;
    pInt = nullptr;
    return 0;
}

