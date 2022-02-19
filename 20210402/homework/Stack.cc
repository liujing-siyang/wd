#include <iostream>

using std::cout;
using std::endl;

class Stack
{
public:
    Stack(int sz = 10)
    : _top(-1)
    , _size(sz)
    , _data(new int[_size]())
    {
        cout << "Stack(size_t = 10)" << endl;
    }

    bool full()
    {
        return (_top == _size - 1);
    }

    bool empty()
    {
#if 0
        if(-1 == _top)
        {
            return true;
        }
        else
        {
            return false;
        }
#endif
        return -1 == _top;
    }

    void push(int value)
    {
        if(!full())
        {
            _data[++_top] = value;
        }
        else
        {
            cout << "The stack is full, cannot push any data" << endl;
            return;
        }
    }

    void pop()
    {
        if(!empty())
        {
            --_top;
        }
        else
        {
            cout << "The stack is empty" << endl;
            return;
        }
    }

    int top()
    {
        return _data[_top];
    }

    ~Stack()
    {
        cout << "~Stack()" << endl;
        if(_data)
        {
            delete [] _data;
            _data = nullptr;
        }
    }
private:
    int _top;
    int _size;
    int *_data;
};

int main(int argc, char **argv)
{
    Stack sta(12);
    cout << "该栈是不是空的？" << sta.empty() << endl;
    sta.push(1);
    cout << "该栈是不是满的？" << sta.full() << endl;
    for(int idx = 2; idx != 15; ++idx)
    {
        sta.push(idx);
    }
    cout << "该栈是不是满的？" << sta.full() << endl;
    while(!sta.empty())
    {
        cout << sta.top() << endl;
        sta.pop();
    }
    cout << "该栈是不是空的？" << sta.empty() << endl;
    return 0;
}

