#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

//纯虚函数 + 继承实现多态
//
//
//面向对象的设计原则：开闭原则
//对扩展开放，对修改关系
//
//
class Figure
{ 
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
};

class Circle
: public Figure
{ 
public:
    Circle(double radius)
    : _radius(radius)
    {

    } 

    void display() const override
    {
        cout << "Circle";
    }

    double area() const override
    {
        return 3.14159 * _radius * _radius;
        
    }
private:
    double _radius;
};

class Rectangle
: public Figure
{ 
public:
    Rectangle(double length, double width)
    : _length(length)
    , _width(width)
    {

    } 
    void display() const override
    {
        cout << "Rectangle";
    } 
    double area() const override
    {
        return _length * _width;
        
    }
private:
    double _length;
    double _width;
};
class Triangle
: public Figure
{ 
public:
    Triangle(double a, double b, double c)
    : _a(a)
    , _b(b)
    , _c(c)
    { 

    } 
    
    void display() const
    {
        cout << "Triangle";
    } 
    //海伦公式计算三角形的面积
    double area() const
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
    fig.display();
    cout << "'s area : " << fig.area() << endl;
}

int main()
{
    Circle circle(10);
    Rectangle rectangle(10, 20);
    Triangle triangle(3, 4, 5);

    func(circle);
    func(rectangle);
    func(triangle);

    return 0;

}
