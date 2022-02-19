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

void test4()
{
    cout << "sizeof(Computer) = " << sizeof(Computer) << endl;

    cout << "初始情况下，总价格: " << endl;
    Computer::printTotalPrice();
    
    cout << endl;
    Computer com1("Thinkpad", 8000);
    cout << "com1 = ";
    com1.print();
    com1.printTotalPrice();

    cout << endl;
    Computer com2("mac", 20000);
    cout << "com2 = ";
    /* Computer::print();//error */
    com2.print();
    com2.printTotalPrice();
    com1.printTotalPrice();
    Computer::printTotalPrice();//可以使用类名加作用域限定符的形式进行调用
}

void test5()
{
    //对于非const对象，既可以调用const版本的成员函数，可以调用
    //非const版本的成员函数，默认情况下，调用非const版本的成员函数
    Computer com1("Thinkpad", 8000);
    cout << "com1 = ";
    com1.print();

    cout << endl;
    //const int a = 10;
    //const对象调用const版本的成员函数,不能调用非const版本的函数
    const Computer com2("mac", 20000);
    cout << "com2 = ";
    com2.print();
}
int main(int argc, char **argv)
{
    test5();
    return 0;

}
