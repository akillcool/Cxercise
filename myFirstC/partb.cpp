//partb.cpp
#include "stdafx.h"	

extern int count;		//�����������ⲿ����

static int total = 0;		//��̬���壬�ڲ�����
//void accumulate(int k); ����ԭ�͵�������ѡ����Ȼ�ڴ��ļ��ж����ˣ����ǲ�û�б�����
void accumulate(int k)
{
	static int subtotal = 0;		//��̬��������

	if (k <= 0)
	{
		printf("loop cycle: %d\n", count);
		printf("subtotal: %d; total: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}
}