//array2d - 处理二维数组的函数

#include <stdio.h>
#define ROWS 3
#define COLS 4

void show2d(int[][COLS], int rows);
void copy2d(int[][COLS], int[][COLS], int);
void copy1d(int[], int[], int);

int main(void)
{
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	int target[ROWS][COLS];

	show2d(junk, ROWS);
	copy2d(junk, target, ROWS);
	show2d(target, ROWS);

	while (true);
	return 0;
}

void show2d(int ar[][COLS], int rows)
{
	int c;
	int r;

	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < COLS; c++)
			printf("%d\t", ar[r][c]);
		printf("\n");
	}
}

//void copy2d(const int ar[][COLS], int target[][COLS], int)
//{
//	int c;
//	int r;
//	int c_t = 0;
//	int r_t = 0;
//
//	for ( c = 0; c < COLS; c++)
//		for ( r = 0; r < ROWS; r++)
//		{
//			target[r_t][c_t] = ar[r][c];
//		}
//}

void copy2d(int source[][COLS], int target[][COLS], int n)
{
	int i;
	for (i = 0; i<n; i++)
		copy1d(*(source + i), target[i], COLS);
}

void copy1d(int a1[], int a2[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		a2[i] = a1[i];
}