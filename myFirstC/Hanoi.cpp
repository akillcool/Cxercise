//Tower of Hanoi
#include <stdio.h>
void Hanoi(int n, char a, char b, char c);

static int count = 0;

int main(void)
{
	int n;
	printf("������Ҫ�ƶ��Ŀ�����");
	scanf_s("%d", &n);
	Hanoi(n, 'a', 'b', 'c');
	printf("%d\n", count);
	return 0;
}

void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("\t%c->%c\n", a, c);    //��nֻ��1����ʱ��ֱ�Ӵ�a�ƶ���c
		++count;
	}
	else
	{
		Hanoi(n - 1, a, c, b);		//��n-1��Ҫ��aͨ��c�ƶ���b
		printf("\t%c->%c\n", a, c);
		++count;
		Hanoi(n - 1, b, a, c);		//n-1���ƶ�����֮��b�俪ʼ�̣�bͨ��a�ƶ���c
	}
}