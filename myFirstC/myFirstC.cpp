#include <stdio.h>
double show(int, const double[]);

int main(void)
{
	int i;
	double array[5] = { 4.5, 3.8, 8.9, 2.1, 5.6 };

	for ( i = 0; i < 5; i++)
	{
		printf("%.1lf\t", array[i]);
	}
	printf("\nThe substract of max and min is %.1lf\n", show(5, array));

	while (true);
	return 0;
}

double show(int n, const double ar[])
{
	int i;
	double max;
	double min;

	max = ar[0];
	min = ar[0];

	for ( i = 0; i < n; i++)
	{
		if (max < ar[i])
			max = ar[i];
		if (min > ar[i])
			min = ar[i];
	}
	return max - min;
}

