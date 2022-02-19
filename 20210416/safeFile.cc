#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class SafeFile
{
public:
    SafeFile(FILE *fp)
    : _fp(fp)
    {
        cout << "SafeFile(FILE *)" << endl;
    }

    void write(const string &msg)
    {
        fwrite(msg.c_str(), 1, msg.size(), _fp);
    }

    ~SafeFile()
    {
        cout << "~SafeFile()" << endl;
        if(_fp)
        {
            fclose(_fp);
            cout << "fclose(_fp)" << endl;
        }
    }
private:
    FILE *_fp;
};
int main(int argc, char **argv)
{
    string msg = "hello,world";
    SafeFile sf(fopen("test.txt", "a+"));//sf栈对象
    sf.write(msg);

    return 0;
}

