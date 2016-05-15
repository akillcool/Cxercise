#include <stdio.h>
void copy_ptr(double *, double *, int);


int main(void)
{
	double source[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	double target[3];

	copy_ptr(source, target, 5);

	while (true);
	return 0;
}

void copy_ptr(double *ptr1, double *ptr2, int n)
{
	int i;

	for ( i = 2; i < n; i++)
	{
		*(ptr2 + i) = *(ptr1 + i);
		printf("%.1lf\t", *(ptr2 + i));
	}
}