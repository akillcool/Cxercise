// myFirstC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
double power(double n, int p);  /* ANSI prototype */

int main(void)
{
	double x, xpow;
	int n;

	printf("Enter a number and the integer power");
	printf(" to which\nthe number will be raised. Enter q");
	printf(" to quit.\n");
	while (scanf_s("%lf%d", &x, &n) == 2)
	{
		xpow = power(x, n);       /* function call           */
		printf("%.3g to the power %d is %.5g\n", x, n, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip -- bye!\n");

	while (true);
	return 0;
}

double power(double n, int p)
{
	int i;
	double xpow = 1;

	if (n == 0 && p != 0)
		return 0;
	if (p == 0)
		return 1;


	else if (p > 0)
	{
		for (i = 0; i < p; i++)
			xpow *= n;
		return xpow;
	}
	else
	{
		xpow = power(n,-p);
		return 1 / xpow;
	}
}