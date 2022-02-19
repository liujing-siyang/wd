#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::string;
using std::ifstream;

string int2String(int number)
{
    ostringstream oss;
    oss << number;
    return oss.str();
}
void test()
{
    int value = 100;
    string str1 = int2String(value);

    cout << "str1 = " << str1 << endl;
}

void test2()
{
    int number1 = 10;
    int number2 = 20;
    stringstream ss;
    ss << "number1= " << number1 << " ,number2= " << number2 << endl;
    string str1 = ss.str();
    cout << str1;

    string key;
    int value;
    while(ss >> key >> value)
    {
        cout << key << "       " << value << endl;
    }
}

void readConfig(const string &filename)
{
    ifstream ifs(filename);
    if(!ifs)
    {
        std::cerr << "ifstream open" << filename << " error!" << endl;
        return;
    }

    string line;
    while(getline(ifs, line))
    {
        istringstream iss(line);
        string key, value;
        iss >> key >> value;
        cout << key << "    " << value << endl;
    }

    ifs.close();
}
void test3()
{
    readConfig("My.conf");
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}

