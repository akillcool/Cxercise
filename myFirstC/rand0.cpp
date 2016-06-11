//rand0.cpp -- 产生随机数
#include "stdafx.h"

static unsigned long int next = 1;
int rand0(void)
{
	//产生伪随机数的公式
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}