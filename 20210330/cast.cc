#include <iostream>

using std::cout;
using std::endl;


void test()
{
    int iNumber = 10;
    float fNumber = 12.34;
    iNumber = (int)fNumber;
    iNumber = int(fNumber);
}

void test2()
{
    int iNumber = 10;
    float fNumber = 12.34;
    iNumber = static_cast<int>(fNumber);
    cout << "iNumber = " << iNumber << endl;

    void *pret = malloc(sizeof(int));
    int *pInt = static_cast<int *>(pret);

    free(pInt);
}

void test3()
{
    const int number = 10;
    /* int *pInt = &number;//error */
    int *pInt = const_cast<int *>(&number);
    *pInt = 20;//未定义的行为
    cout << "number = " << number << endl;
    cout << "*pInt = " << *pInt << endl;
    printf("number's address : %p\n", &number);
    printf("pInt's address : %p\n", pInt);
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}

