#include <math.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;
using std::function;

//function + bind可以取代纯虚函数 + 继承来实现多态
class Figure
{ 
public:
    /* typedef function<void()> DisplayCallback;//C的写法 */
    using DisplayCallback = function<void()>;//参数
    using AreaCallback = function<double()>;

    DisplayCallback _displayCallback;
    AreaCallback _areaCallback;
    
    /* virtual void display() const = 0; */
    /* virtual double area() const = 0; */
    //注册回调函数
    /* void setDisplayCallback(function<void()> &&cb) */
    //引用折叠
    //1.所有右值引用折叠到右值引用上仍然是一个右值引用。（A&& && 变成 A&&）
    //2.所有的其他引用类型之间的折叠都将变成左值引用。 （A& & 变成 A&; A& && 变成 A&; A&& & 变成 A&）
    void setDisplayCallback(DisplayCallback &&cb)//接收一个可调用对象作为参数
    {
        _displayCallback = std::move(cb);//_displayCallback还是一个可调用对象
    }

    void setAreaCallback(AreaCallback &&cb)
    {
        _areaCallback = std::move(cb);
    }


    //执行回调函数
    void handleDisplayCallback() const
    {
        if(_displayCallback)
        {
            _displayCallback();
        }
    }

    double handleAreaCallback() const
    {
        if(_areaCallback)
        {
            return _areaCallback();
        }
        else
        {
            return 0;
        }
    }
};

class Circle
{ 
public:
    Circle(double radius)
    : _radius(radius)
    {

    } 

    void display(int x) const 
    {
        cout << "Circle";
    }

    double area() const 
    {
        return 3.14159 * _radius * _radius;
        
    }
private:
    double _radius;
};

class Rectangle
{ 
public:
    Rectangle(double length, double width)
    : _length(length)
    , _width(width)
    {

    } 
    void show() const 
    {
        cout << "Rectangle";
    } 
    double showArea() const 
    {
        return _length * _width;
        
    }
private:
    double _length;
    double _width;
};
class Triangle
{ 
public:
    Triangle(double a, double b, double c)
    : _a(a)
    , _b(b)
    , _c(c)
    { 

    } 
    
    void print() const
    {
        cout << "Triangle";
    } 
    //海伦公式计算三角形的面积
    double printArea() const
    {
        double p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

private:
    double _a;
    double _b;
    double _c;
};

void func(Figure &fig)
{
    fig.handleDisplayCallback();
    cout << "'s area : " << fig.handleAreaCallback() << endl;
}

int main()
{
    Circle circle(10);
    Rectangle rectangle(10, 20);
    Triangle triangle(3, 4, 5);

    Figure fig;
    
    //Circle::display为一个可调用对象，通过对bind的调用生成新的可调用对象f,然后可以通过这个新对象f给display传参
    //auto f = bind(&Circle::display, &circle, 10);
    //fig.setDisplayCallback(f);
    fig.setDisplayCallback(bind(&Circle::display, &circle, 10));
    fig.setAreaCallback(bind(&Circle::area, &circle));
    func(fig);

    fig.setDisplayCallback(bind(&Rectangle::show, &rectangle));
    fig.setAreaCallback(bind(&Rectangle::showArea, &rectangle));
    func(fig);

    fig.setDisplayCallback(bind(&Triangle::print, &triangle));
    fig.setAreaCallback(bind(&Triangle::printArea, &triangle));
    func(fig);

    return 0;

}
