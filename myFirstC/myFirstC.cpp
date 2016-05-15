#include <stdio.h>
int show(int, double[]);

int main(void)
{
	int i;
	double array[5] = { 4.5, 3.8, 8.9, 2.1, 5.6 };

	for ( i = 0; i < 5; i++)
	{
		printf("%.1lf\t", array[i]);
	}
	printf("\nThe index of array's max number is %d.\n", show(5, array));

	while (true);
	return 0;
}

int show(int n, double ar[])
{
	int i;
	int max_ct;
	double max;

	max_ct = 0;
	max = ar[0];

	for ( i = 0; i < n; i++)
	{
		if (max < ar[i])
		{
			max = ar[i];
			max_ct = i;
		}
	}
	return max_ct;
}

