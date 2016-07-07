//reducto.c ѹ���ı�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;

	//��������в���
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.\n", argv[0]);
		exit(1);
	}

	//ʵ������
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"", argv[1]);
		exit(2);
	}

	//ʵ�����
	strcpy(name, argv[1]);
	strcat(name, ".red");
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't creat output file.");
		exit(3);
	}

	//��������
	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
		{
			putc(ch, out);
		}
	}

	//�ر��ļ�
	if (fclose(in)!=0||fclose(out)!=0)
	{
		fprintf(stderr, "Error in closing files.");
	}
	return 0;
}


