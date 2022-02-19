#include "Computer.h"
#include <iostream>

using std::cout;
using std::endl;

/* Computer gCom("xiao", 7000); */

/* Computer("xiaomi", 7000); */
void test()
{
    /* cout << "enter main..." << endl; */
    /* Computer com("lenovo", 6000); */
    /* com.~Computer(); */
    /* com.setBrand("lenovo"); */
    /* com.setPrice(6000); */
    /* com.print(); */

    cout << endl;
    Computer *pc = new Computer("huawei", 10000);

    delete pc;

}


void test2()
{
    Computer com1("Thinkpad", 8000);
    cout << "com1 = ";
    com1.print();

    cout << endl;
    Computer com2 = com1;
    cout << "com2 = ";
    com2.print();

    cout << endl << "设置com1的品牌" << endl;
    com1.setBrand("huawei");
    cout << "com1 = ";
    com1.print();
    cout << "com2 = ";
    com2.print();
}

void test3()
{
    Computer com1("Thinkpad", 8000);
    cout << "com1 = ";
    com1.print();

    cout << endl;
    Computer com2("mac", 20000);
    cout << "com2 = ";
    com2.print();

    cout << endl << "com2 = com1" << endl;
    com2 = com1;
    cout << "com1 = ";
    com1.print();
    cout << "com2 = ";
    com2.print();

    cout << endl << "com1 = com1" << endl;
    com1 = com1;
    cout << "com1 = ";
    com1.print();
}
int main(int argc, char **argv)
{
    test3();
    return 0;

}
