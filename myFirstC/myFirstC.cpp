//PE 11-14 myatof
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
double myatof(char *p);

int main(void)
{
	char a[30] = { 0 };
	while (a[0] != 'q')
	{
		puts("input adouble without +-e:");
		gets_s(a);
		printf("atof: %.5lf\n", atof(a));
		printf("myatof: %.5lf\n", myatof(a));
		printf("difference:%.5lf\n", atof(a) - myatof(a));
		puts("input anycharexcept q to go on.");
		gets_s(a);
	}
	puts("Quit.");
	return 0;
}
double myatof(char *p)//将字符串转换为浮点型，暂时只限小数点格式（如： 342.678）
{
	double n = 0;
	int i = -1;
	while (1)
	{
		if (isdigit(*p)) //如果是数字
		{
			n = n * 10 + (*p) - '0';
			if (i != -1) 
				i++; //小数位数 i计数
		}
		else if (*p == '.' && i == -1) //如果是第一个小数点
			i = 0; //开启小数位数 i计数
		else
			break;
		p++;
	}
	for (; i>0; i--) //根据小数位数i，将 n取为原来的(10^i)分之一
		n /= 10; 
	return n;
}