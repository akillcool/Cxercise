//append.c - �Ѷ���ļ�������׷�ӵ�һ���ļ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define SLEN 81

void append(FILE *source, FILE *dest);
int main(void)
{
	FILE *fa, *fs;	//faָ��׷�ӵ�Ŀ���ļ���fs��Դ�ļ�
	int files = 0;	//׷�ӵ��ļ�����
	char file_app[SLEN];	//Ŀ���ļ�����
	char file_src[SLEN];	//Դ�ļ�����

	puts("Enter name of destination file: ");
	gets_s(file_app);

	if ((fa = fopen(file_app, "a")) == NULL)		//��Ŀ���ļ�
	{
		fprintf(stderr, "Can't open %s\n", file_app);
		exit(2);
	}

	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)	//�������������
	{
		fputs("Can't create output buffer.", stderr);
		exit(3);
	}

	puts("Enter name of first source file(empty line to quit.)");
	while (gets_s(file_src) && file_src[0] != '\0')
	{
		if (strcmp(file_app, file_src) == 0)	//�Ƚ������ļ�����ͬ������
		{
			fputs("Can't append file to itself.\n", stderr);
		}
		else if ((fs = fopen(file_src, "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\n", file_src);
		}
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)	//�������뻺����
			{
				fputs("Can't create input buffer", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)	//�ж��Ƿ��ȡ����
			{
				fprintf(stderr, "Error in reading file %s\n", file_src);
			}
			if (ferror(fa) != 0)
			{
				fprintf(stderr, "Error in writing file %s\n", file_app);
			}
			fclose(fs);
			files++;
			printf("File %s appended.\n", file_src);
			puts("Next file(empty line to quit):");
		}
	}
	printf("Done! %d files appended.\n", files);
	fclose(fa);

	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];		//����һ��

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}

