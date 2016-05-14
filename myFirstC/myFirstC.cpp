// myFirstC.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
void copy_arr(double[], double[], int);
void copy_ptr(double *, double *, int);

int main(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];

	copy_arr(source, target1, 5);
	printf("\n");
	copy_ptr(source, target2, 5);

	while (true);
	return 0;
}

void copy_arr(double ar[], double target[], int n)
{
	int i;

	for ( i = 0; i < n; i++)
	{
		target[i] = ar[i];
		printf("%.2lf\t", target[i]);
	}
}

void copy_ptr(double *ptr1, double *ptr2, int n)
{
	int i;

	for ( i = 0; i < n; i++)
	{
		*(ptr2 + i) = *(ptr1 + i);
		printf("%.2lf\t", *(ptr2 + i));
	}
}