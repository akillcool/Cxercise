//r_drive0.cpp������rand0����

#include <stdio.h>
#include <time.h>

extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
	int count;

	printf("Using current time as seed.\n");
	srand1((unsigned int)time(0));		//����ǰʱ����Ϊ����
	for ( count = 0; count < 5; count++)
	{
		printf("%hd\n", rand1());
	}
	printf("Done\n");

	while (true);
	return 0;
}