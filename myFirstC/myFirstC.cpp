// myFirstC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void to_base_n(unsigned long n,int base);

int main(void)
{
	unsigned long number;
	int m;

	printf("Enter an integer (q to quit): \n");
	while (scanf_s("%lu", &number) == 1 )
	{
		printf("Enter another integer: \n");
		scanf_s("%d", &m);
		printf("Binary equivalent: ");
		to_base_n(number, m);
		putchar('\n');
		printf("Enter an integer (q to quit): \n");
	}
	printf("Done.\n");

	while (true);
	return 0;
}

void to_base_n(unsigned long n,int base)
{
	int r;

	r = n % base;
	if (n >= base)
		to_base_n(n / base, base);
		//to_base_n(n,m);
	putchar('0' + r);

	return;
}