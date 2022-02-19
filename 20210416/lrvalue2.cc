#include <iostream>

using std::cout;
using std::endl;


void test()
{
    int a = 10;
    int &ref = a;//ref是左值
}

int arr[10] = {1, 3, 5, 7, 9};

int &getIndex(int idx)//左值
{
    return arr[idx];
}

const int &getX(int x)
{
    return 10;
}

void test2()
{
    cout << "getIndex(3) = " << getIndex(3) << endl;
    getIndex(3) = 100;
    &getIndex(3);
    cout << "getIndex(3) = " << getIndex(3) << endl;
    &getX(10);
}
int main(int argc, char **argv)
{
    cout << "Hello world" << endl;
    return 0;
}

