 ///
 /// @file    Figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 14:31:43
 ///
 
#include <math.h>
#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

//配置文件的形式:
//	*.txt 
//	xml
//	json
//
class Figure
{
public:
	virtual void display() const =0;
	virtual double area()=0;

	virtual ~Figure() {}
};

class Circle
: public Figure
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void display() const
	{	cout << "circle";	}

	double area()
	{
		return 3.14159 * _radius * _radius;
	}

	~Circle() {	cout << "~Circle()" << endl;	}

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
	{}

	~Rectangle() { cout << "~Rectangle()" << endl; }

	void display() const
	{	cout << "rectangle";	}

	double area()
	{	return _length * _width;	}

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
	{}

	~Triangle() {	cout << "~Triangle()" << endl;	}

	void display() const
	{	cout << "triangle";}

	double area()
	{
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	double _a;
	double _b;
	double _c;
};

void display(Figure * fig)
{
	fig->display();
	cout << "的面积是:" << fig->area() << endl;
}


//工厂模式
//	1. 遵循开闭原则
//	2. 遵循单一职责原则
//
//应用场景：
// 1. 并不是什么时候都适合使用工厂模式的
// 2. 对于简单对象，直接创建即可
// 3. 工厂模式针对与复杂对象, 批量生产的
class Factory
{
public:
	virtual Figure * create() = 0;
	virtual ~Factory() {}
};

class RectangleFactory
: public Factory
{
public:
	Figure * create()
	{
		//预处理.. load 配置文件
		return new Rectangle(10, 11);
	}
};	
		
class CircleFactory
: public Factory
{
public:
	Figure * create()
	{
		//预处理.. load 配置文件
		return new Circle(10);
	}
};	

class TriangleFactory
: public Factory
{
public:
	Figure * create()
	{
		//预处理.. load 配置文件
		return new Triangle(3, 4, 5);
	}
};	



int main(void)
{
	unique_ptr<Factory> rectFact(new RectangleFactory());
	unique_ptr<Figure> rect(rectFact->create());

	unique_ptr<Factory> circleFact(new CircleFactory());
	unique_ptr<Figure> circle(circleFact->create());

	unique_ptr<Factory> triangleFact(new TriangleFactory());
	unique_ptr<Figure> triangle(triangleFact->create());

	display(rect.get());
	display(circle.get());
	display(triangle.get());

	return 0;
}

