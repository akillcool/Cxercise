#include <stdio.h>
void show(int[][5], int);
void dou(int[][5], int);

int main(void)
{
	int source[3][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 0},
		{3, 4, 5, 6, 7},
	};

	show(source, 3);
	printf("\n");
	dou(source, 3);
	show(source, 3);


	while (true);
	return 0;
}

void show(int ar[][5], int rows)
{
	int i, j;

	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			printf("%d\t", ar[i][j]);
		}
		printf("\n");
	}
}

void dou(int ar[][5], int rows)
{
	int i, j;

	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			ar[i][j] *= 2;
		}
	}
}