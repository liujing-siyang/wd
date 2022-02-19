#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//要求：只能创建栈对象
//做法：将operator new/delete设置为私有的

class Student
{
public:
    Student(int id, const char *name)
    : _id(id)
    , _name(new char[strlen(name) + 1]())
    {
        cout << "Student(int, const char *)" << endl;
        strcpy(_name, name);
    }
private:
    static void *operator new(size_t sz)
    {
        /* printf("this : %p\n", this); */
        cout << "void *operator new(size_t)" << endl;

        void *pret = malloc(sz);

        return pret;
    }

    static void operator delete(void *ptr)
    {
        /* printf("this : %p\n", this); */
        cout << "void operator delete (void *)" << endl;
        free(ptr);
    }
public:

    void print() const
    {
        cout << "id: " << _id << endl
             << "name: " << _name << endl;
    }
/* private: */
    ~Student()
    {
        cout << "~Student()" << endl;
        if(_name)
        {
            delete [] _name;
            _name = nullptr;
        }
    }
private:
    int _id;
    char *_name;
};
int main(int argc, char **argv)
{
    //Q:栈对象创建的时候需要哪些条件？
    //A:构造函数与析构函数都不能设置为私有的
    Student stu(12, "xiaoming");//栈对象

    /* Student *pstu = new Student(10, "xiaohong");//error */
    /* pstu->print(); */

    //Q:对象的销毁与析构函数的执行是不是等价的？
    //A:堆对象时候，析构函数的执行是对象销毁中的一部分
    /* delete pstu; */
    return 0;
}

