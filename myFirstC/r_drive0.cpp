//r_drive0.cpp������rand0����

#include <stdio.h>

extern int rand0(void);

int main(void)
{
	int count;

	for ( count = 0; count < 5; count++)
	{
		printf("%hd\n", rand0());
	}

	while (true);
	return 0;
}