//r_drive0.cpp，测试rand0函数

#include <stdio.h>
extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
	int count;
	unsigned seed;

	printf("Please enter your choice for seed.\n");
	while (scanf_s("%u", &seed) == 1)
	{
		srand1(seed);		//重置种子
		for ( count = 0; count < 5; count++)
		{
			printf("%hd\n", rand1());
		}
		printf("Please enter next seed(q to quit):\n");
	}
	printf("Done\n");

	while (true);
	return 0;
}