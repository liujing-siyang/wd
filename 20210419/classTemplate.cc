#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T, size_t sz = 10>
class Stack
{
public:
    Stack()
    : _top(-1)
    , _data(new T[sz]())
    {

    }
    ~Stack();
    bool full();
    bool empty();
    void push(const T &value);
    void pop();
    T top();
private:
    int _top;
    T *_data;
};

template <typename T, size_t sz>
Stack<T, sz>::~Stack()
{
    if(_data)
    {
        delete [] _data;
        _data = nullptr;
    }
}
template <typename T, size_t sz>
bool Stack<T, sz>::full()
{
    return _top == sz - 1; 
}

template <typename T, size_t sz>
bool Stack<T, sz>::empty()
{
    return -1 == _top;
}

template <typename T, size_t sz>
void Stack<T, sz>::push(const T &value)
{
    if(!full())
    {
        _data[++_top] = value;
    }
    else
    {
        cout << "The stack is full" << endl;
    }
}

template <typename T, size_t sz>
void Stack<T, sz>::pop()
{
    if(!empty())
    {
        --_top;
    }
    else
    {
        cout << "The stack is empty" << endl;
    }
}

template <typename T, size_t sz>
T Stack<T, sz>::top()
{
    return _data[_top];
}

void test()
{
    Stack<int, 15> st;
    cout << "该栈是不是空的?" << st.empty() << endl;
    st.push(1);
    cout << "该栈是不是满的?" << st.full() << endl;

    for(size_t idx = 2; idx != 20; ++idx)
    {
        st.push(idx);
    }
    cout << "该栈是不是满的?" << st.full() << endl;

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

void test2()
{
    Stack<string> st;
    cout << "该栈是不是空的?" << st.empty() << endl;
    st.push(string("aa"));
    cout << "该栈是不是满的?" << st.full() << endl;

    for(size_t idx = 1; idx != 20; ++idx)
    {
        st.push(string(2, 'a' + idx));
    }
    cout << "该栈是不是满的?" << st.full() << endl;

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

