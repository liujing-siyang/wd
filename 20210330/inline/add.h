#ifndef __ADD_H_
#define __ADD_H_

//对于内联函数（inline函数）而言，不能写成头文件与实现文件的形式
//或者说不能将声明与实现分开
//
//内联函数是一些小函数，函数体比较简单，不要有for、while等复杂语句
inline
int add(int x, int y);

#include "add.cc"


#endif
