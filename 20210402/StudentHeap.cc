#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//要求：只能生成堆对象?
//做法：将析构函数设置为私有的

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

    void print() const
    {
        cout << "id: " << _id << endl
             << "name: " << _name << endl;
    }

    void destroy()
    {
        /* this->~Student();//error */
        delete this;
        /* free(this); */
    }
private:
    ~Student()
    {
        /* delete this;//error */
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
    /* Student stu(12, "xiaoming");//栈对象，error */

    Student *pstu = new Student(10, "xiaohong");
    pstu->print();

    //Q:对象的销毁与析构函数的执行是不是等价的？
    //A:堆对象时候，析构函数的执行是对象销毁中的一部分
    /* delete pstu;//error */

    pstu->destroy();
    return 0;
}

