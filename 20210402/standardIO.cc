#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void printCinStatus()
{
    cout << "cin's badbit = " << cin.bad() << endl
         << "cin.failbit = " << cin.fail() << endl
         << "cin.eofbit = " << cin.eof() << endl
         << "cin.goodbit = " << cin.good() << endl;
}

void test()
{
    int number = 10;
    printCinStatus();
    cin >> number;
    printCinStatus();
    cin.clear();//重置流的状态
    printCinStatus();
    /* cin.ignore(1024, '\n');//清空缓冲区 */
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区
    printCinStatus();
    cout << "number = " << number << endl;

    string line;
    cin >> line;
    cout << "line = " << line << endl;
}

void test2()
{
    int number = 10;
    //ctrl + d
    while(cin >> number, !cin.eof())
    {
        if(cin.bad())
        {
            std::cerr << "The stream bad" << endl;
            return;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区
            cout << "pls input valid data" << endl;
        }
        else
        {
            cout << "number = " << number << endl;
        }
    }
}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

