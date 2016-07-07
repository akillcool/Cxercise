//append.c - 把多个文件的内容追加到一个文件中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define SLEN 81

void append(FILE *source, FILE *dest);
int main(void)
{
	FILE *fa, *fs;	//fa指向追加的目的文件，fs是源文件
	int files = 0;	//追加的文件个数
	char file_app[SLEN];	//目的文件名称
	char file_src[SLEN];	//源文件名称

	puts("Enter name of destination file: ");
	gets_s(file_app);

	if ((fa = fopen(file_app, "a")) == NULL)		//打开目的文件
	{
		fprintf(stderr, "Can't open %s\n", file_app);
		exit(2);
	}

	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)	//创建输出缓冲区
	{
		fputs("Can't create output buffer.", stderr);
		exit(3);
	}

	puts("Enter name of first source file(empty line to quit.)");
	while (gets_s(file_src) && file_src[0] != '\0')
	{
		if (strcmp(file_app, file_src) == 0)	//比较两个文件，相同则跳过
		{
			fputs("Can't append file to itself.\n", stderr);
		}
		else if ((fs = fopen(file_src, "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\n", file_src);
		}
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)	//创建输入缓冲区
			{
				fputs("Can't create input buffer", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)	//判断是否读取错误
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
	static char temp[BUFSIZE];		//分配一次

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}

