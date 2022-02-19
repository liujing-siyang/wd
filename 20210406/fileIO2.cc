#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

void test()
{
    ifstream ifs("Point.cc");
    if(!ifs.good())
    {
        std::cerr << "ifs stream is not good" << endl;
        return;
    }
    //读文件操作
    
    string line;
    //对于文件输入流而言，默认以空格为分隔符
    /* while(ifs >> line)//cin >> number */
    while(getline(ifs, line))//cin >> number
    {
        cout << line << endl;
    }

    ifs.close();
}

void test2()
{
    ifstream ifs("Point.cc");
    if(!ifs.good())
    {
        std::cerr << "ifs stream is not good" << endl;
        return;
    }
    
    string line[100];
    int idx = 0;
    while(getline(ifs, line[idx]))//cin >> number
    {
        ++idx;
        cout << line[idx] << endl;
    }

    ifs.close();
}

void test3()
{
    ifstream ifs("Point.cc");
    if(!ifs.good())
    {
        std::cerr << "ifs stream is not good" << endl;
        return;
    }
    
    vector<string> vec;
    vec.reserve(50);
    string line;
    while(getline(ifs, line))//cin >> number
    {
        vec.push_back(line);
    }

    for(size_t idx = 0; idx != vec.size(); ++idx)
    {
        cout << vec[idx] << endl;
    }

    cout <<endl << endl;
    cout << "vec[28] = " << vec[28] << endl;
    ifs.close();
}

void test4()
{
    ifstream ifs("Point.cc");
    if(!ifs.good())
    {
        std::cerr << "ifs stream is not good" << endl;
        return;
    }

    //默认情况下，对于文件输出流而言，当文件不存在的时候，就创建文件
    //如果文件存在，就清空文件，然后再去进行写操作
    ofstream ofs("wuhan.txt");
    if(!ofs.good())
    {
        std::cerr << "ofs ofstream not good " << endl;
        ifs.close();
        return;
    }

    string line;
    while(getline(ifs, line))
    {
        ofs << line << endl;
    }

    ifs.close();
    ofs.close();

}

void test5()
{
    //对于文件输入输出流而言，当文件不存在的时候就打开失败
    string filename("test.txt");
    fstream fs(filename);
    if(!fs.good())
    {
        std::cerr << "fs fstream is not good" << endl;
        return;
    }
   cout << "pos = " << fs.tellp() << endl;

    int number = 0;
    for(size_t idx = 0; idx != 5; ++idx)
    {
        std::cin >> number;
        fs << number << " ";
    }

    cout << "pos = " << fs.tellp() << endl;

    fs.seekp(0);
    /* fs.seekp(0, std::ios::beg); */

    number = 10;
    for(size_t idx = 0; idx != 5; ++idx)
    {
        
        fs >> number;
        cout << number << " ";
    }
    cout << endl;


    fs.close();

}

void test6()
{
    ifstream ifs("Point.cc", std::ios::ate);
    if(!ifs.good())
    {
        std::cerr << "ifs stream is not good" << endl;
        return;
    }
    
    cout << "pos = " << ifs.tellg() << endl;
    

    ifs.close();

}

void test7()
{
    ofstream ofs("wuhan.txt", std::ios::app);
    if(!ofs.good())
    {
        std::cerr << "ofs ofstream not good " << endl;
        return;
    }

    cout << "pos = " << ofs.tellp() << endl;
    ofs.close();

}
int main(int argc, char **argv)
{
    test7();
    return 0;
}

