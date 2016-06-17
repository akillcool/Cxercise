//Tower of Hanoi
#include <stdio.h>
void Hanoi(int n, char a, char b, char c);

static int count = 0;

int main(void)
{
	int n;
	printf("请输入要移动的块数：");
	scanf_s("%d", &n);
	Hanoi(n, 'a', 'b', 'c');
	printf("%d\n", count);
	return 0;
}

void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("\t%c->%c\n", a, c);    //当n只有1个的时候直接从a移动到c
		++count;
	}
	else
	{
		Hanoi(n - 1, a, c, b);		//第n-1个要从a通过c移动到b
		printf("\t%c->%c\n", a, c);
		++count;
		Hanoi(n - 1, b, a, c);		//n-1个移动过来之后b变开始盘，b通过a移动到c
	}
}