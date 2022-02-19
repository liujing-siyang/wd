#include <iostream>
#include <memory>

using std::cout;
using std::endl;

template <class T>
class Vector
{
public:
    typedef T* iterator;//C里面的写法
    /* using iterator = T *;//C++11的写法 */

    /* T *begin() */
    iterator begin()
    {
        return _start;
    }

    iterator end()
    {
        return _finish;
    }

    Vector()
    : _start(nullptr)
    , _finish(nullptr)
    , _end_of_storage(nullptr)
    {

    }

    ~Vector();
    void push_back(const T &t);
    void pop_back();
    int size() const;
    int capacity() const;
private:
    void reallocator();
private:
    static std::allocator<T> _alloc;//静态数据成员，放在类外初始化

    T *_start;
    T *_finish;
    T *_end_of_storage;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::~Vector()
{
    if(_start)
    {
        while(_finish != _start)
        {
            _alloc.destroy(--_finish);//空间中的对象进行销毁
        }
        _alloc.deallocate(_start, capacity());//释放空间
    }
}

template <typename T>
void Vector<T>::push_back(const T &t)
{
    if(size() == capacity())
    {
        reallocator();//要进行扩容
    }
    if(size() < capacity())
    {
        _alloc.construct(_finish++, t);//对象的构建
    }
}

template <typename T>
void Vector<T>::pop_back()
{
    if(size() > 0)
    {
        _alloc.destroy(--_finish);//对象销毁
    }
}

template <typename T>
int Vector<T>::size() const
{
    return _finish - _start;
}

template <typename T>
int Vector<T>::capacity() const
{
    return _end_of_storage - _start;
}

template <typename T>
void Vector<T>::reallocator()//自己实现的扩容
{
    int oldCapacity = capacity();
    int newCapacity = 2 * oldCapacity > 0 ? 2 * oldCapacity : 1;

    T *ptmp = _alloc.allocate(newCapacity);//申请空间
    if(_start)
    {
        /* std::copy(_start, _finish, ptmp);//把老空间上的对象拷贝到新的空间来 */
        std::uninitialized_copy(_start, _finish, ptmp);//ptmp上没有对象,所以使用未初始化的copy算法
        while(_finish != _start)
        {
            //考虑边界条件
            _alloc.destroy(--_finish);//老的空间中的对象进行销毁
        }
        _alloc.deallocate(_start, oldCapacity);//释放老的空间
    }

    _start = ptmp;
    _finish = _start + oldCapacity;
    _end_of_storage = _start + newCapacity;
}

template <typename Container>
void display(const Container &c)
{
    cout << "c.size() = " << c.size() << endl
         << "c.capacity() = " << c.capacity() << endl;
}
void test()
{
    Vector<int> number;
    display(number);

    cout << endl;
    number.push_back(1);
    display(number);

    cout << endl;
    number.push_back(2);
    display(number);

    cout << endl;
    number.push_back(3);
    display(number);

    cout << endl;
    number.push_back(4);
    display(number);

    cout << endl;
    number.push_back(4);
    display(number);

    for(auto &elem : number)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}
