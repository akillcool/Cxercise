//partb.cpp
#include "stdafx.h"	

extern int count;		//引用声明，外部链接

static int total = 0;		//静态定义，内部链接
//void accumulate(int k); 函数原型的声明可选，虽然在此文件中定义了，但是并没有被调用
void accumulate(int k)
{
	static int subtotal = 0;		//静态，空链接

	if (k <= 0)
	{
		printf("loop cycle: %d\n", count);
		printf("subtotal: %d; total: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}
}