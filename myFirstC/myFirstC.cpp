#include <stdio.h>
#include <ctype.h>
char *read(char *str);

int main(void)
{
	char ch;
	char target[81];

	if(read(target) != NULL)
		puts(target);
	ch = getchar();
	puts("TEST");
	putchar(ch);
	puts("Done.\n");
	while (true);
	return 0;
}

char *read(char *str)
{
	int i = 0;
	char ch;

	while ((ch = getchar()) != EOF && !isspace(ch))
	{
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
	if (ch == EOF)
		return NULL;
	else
	{
		while (ch != '\n')
			ch = getchar();
		return str;
	}

	return str;
}