//array2d - 处理二维数组的函数

#include <stdio.h>
#define ROWS 3
#define COLS 4

void show2d(int[][COLS], int rows);

int main(void)
{
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};

	show2d(junk, ROWS);

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