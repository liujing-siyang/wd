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


//简单工厂模式(静态工厂方法)
//问题:
//	1. 没有遵循开闭原则
//	2. 没有遵循单一职责原则
class Factory
{
public:
	static Figure * create(const string & figName)
	{
		Figure * fig = nullptr;
		if(figName == "rectangle") {
			//预处理
			fig = new Rectangle(10, 11);
		} else if (figName == "circle") {
			fig = new Circle(10);
		} else if(figName == "triangle") {
			fig = new Triangle(3, 4, 5);
		} 
		/* else if(figName == "diamond") { */
		/* 	fig = new Diamond(); */
		/* } */
		return fig;
	}


	static Figure * createRectangle()
	{
		//读取配置文件 txt  xml  json
		//预处理
		Figure * fig = new Rectangle(5, 6);
		return fig;
	}

	static Figure * createCircle()
	{
		//读取配置文件 txt  xml  json
		//预处理
		Figure * fig = new Circle(10);
		return fig;
	}

	static Figure * createTriangle()
	{
		//输入数据 input, 一般放到配置文件
		//
		//读取配置文件 txt  xml  json
		//预处理
		Figure * fig = new Triangle(3, 4, 5);
		return fig;
	}
};

int main(void)
{
	Figure * rectangle = Factory::createRectangle();
	Figure * circle = Factory::createCircle();
	Figure * triangle = Factory::createTriangle();

	display(rectangle);
	display(circle);
	display(triangle);

	return 0;
}

