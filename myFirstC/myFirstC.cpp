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
double myatof(char *p)//���ַ���ת��Ϊ�����ͣ���ʱֻ��С�����ʽ���磺 342.678��
{
	double n = 0;
	int i = -1;
	while (1)
	{
		if (isdigit(*p)) //���������
		{
			n = n * 10 + (*p) - '0';
			if (i != -1) 
				i++; //С��λ�� i����
		}
		else if (*p == '.' && i == -1) //����ǵ�һ��С����
			i = 0; //����С��λ�� i����
		else
			break;
		p++;
	}
	for (; i>0; i--) //����С��λ��i���� nȡΪԭ����(10^i)��֮һ
		n /= 10; 
	return n;
}