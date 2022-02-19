#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void test()
{
    int a = 10;
    int *pInt = new int(200);
    string s1 = "hello";
    string s2 = "helloworldwuhan";
    string s3 = "helloworldwangdaohaha";
    printf("s1's address : %p\n", s1.c_str());
    printf("s2's address : %p\n", s2.c_str());
    printf("s3's address : %p\n", s3.c_str());
    printf("a's address : %p\n", &a);
    printf("pInt's address : %p\n", pInt);

    cout << "sizeof(s1) = " << sizeof(s1) << endl;
    cout << "sizeof(s3) = " << sizeof(s3) << endl;
    delete pInt;
    pInt = nullptr;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

