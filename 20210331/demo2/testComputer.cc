#include "Computer.h"
#include <iostream>

using std::cout;
using std::endl;

/* Computer gCom("xiao", 7000); */

/* Computer("xiaomi", 7000); */
int main(int argc, char **argv)
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

    return 0;
}
