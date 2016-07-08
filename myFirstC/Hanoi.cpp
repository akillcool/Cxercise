//13.10.5
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF 256

bool has_ch(char ch, char *line);

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	char line[BUF];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [string] [filename]", argv[0]);
		exit(EXIT_FAILURE);
	}
	ch = argv[1][0];
	printf("Now print line that has same string below:\n");
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Failed to open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, BUF, fp)) != NULL)		//TODO
	{
		if (has_ch(ch,line))
		{
			fputs(line, stdout);
		}
	}

	return 0;
}

bool has_ch(char ch, char *line)
{
	while (*line)
	{
		if (ch == *line++)
		{
			return true;
		}
	}
	return false;
}


