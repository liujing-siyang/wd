#include <string.h>//C的头文件
#include <stdlib.h>
#include <iostream>
#include <string>//C++头文件

using std::cout;
using std::endl;
using std::string;

void test()
{
    //C字符串是以'\0'结尾的
    char str1[] = "hello";
    char str2[] = "world";

    str1[0] = 'H';
    printf("str1:%s\n", str1);
    /* str1 = nullptr;//error */

    size_t len1 = sizeof(str1);
    size_t len2 = sizeof(str2);
    size_t len = len1 + len2 - 1;
    char *pstr1 = static_cast<char *>(malloc(len));
    memset(pstr1, 0, len);
    strcpy(pstr1, str1);
    strcat(pstr1, str2);
    printf("pstr1:%s\n", pstr1);

    free(pstr1);
    pstr1 = nullptr;

    const char *pstr = "helloworld";
    /* pstr[0] = 'H';//error */
    printf("pstr: %s\n", pstr);
    pstr = "123";
    printf("pstr: %s\n", pstr);
}

void test2()
{
    //    C++   C 
    string s1 = "hello";
    string s2 = "world";
    string s3 = s1 + s2;//简单，不用考虑与内存相关的操作
    cout << "s3 = " << s3 << endl;

    cout << endl;
    const char *pstr = s3.c_str();
    cout << "pstr = " << pstr << endl;

    //获取C++风格字符串的长度
    cout << endl;
    size_t len1 = s3.size();
    size_t len2 = s3.length();
    cout << "len1 = " << len1 << endl
         << "len2 = " << len2 << endl;

    //打印字符串中的每个字符
    cout << endl;
    for(size_t index = 0; index != len1; ++index)
    {
        cout << s3[index] << " ";
    }
    cout << endl;

    for(auto &elem : s3)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << endl;
    string s4 = s3 + "wuhan";
    cout << "s4 = " << s4 << endl;

    cout << endl;
    string s5 = s4 + 'A';
    cout << "s5 = " << s5 << endl;

    string s6 = s5.append(s1);
    cout << "s6 = " << s6 << endl;
}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

