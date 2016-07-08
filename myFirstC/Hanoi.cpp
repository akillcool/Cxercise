//randombin.c �����ȡ��������IO
#include <stdio.h>
#include <stdlib.h>

#define ARSIZE 1000

int main(void)
{
	double numbers[ARSIZE];
	double value;
	const char *file = "numbers.dat";
	int i;
	long pos;
	FILE *iofile;

	//����һ��double���͵�ֵ
	for (i = 0; i < ARSIZE; i++)
	{
		numbers[i] = 100.0*i + 1.0 / (i + 1);
	}
	//���Դ��ļ�
	if ((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Couldn't open %s for output.\n", file);
		exit(1);
	}
	//�������е������Զ�����д���ļ���
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);

	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Couldn't open %s for random access.\n", file);
		exit(1);
	}

	//���ļ��ж�ȡ��ѡ��Ŀ
	printf("Enter the index in the range 0-%d.\n", ARSIZE - 1);
	scanf("%d", &i);
	while (i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);		//����ƫ����
		fseek(iofile, pos, SEEK_SET);		//��λ
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f.\n", value);
		printf("Next index(out of range to quit.)\n");
		scanf("%d", &i);
	}
	fclose(iofile);
	puts("Bye!");

	return 0;
}



