#include <stdio.h>
char *show_addr(char *str1, char ch);

int main(void)
{
	char source[21] = {"Minecraft"};
	char ch;
	char *addr;

	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
			continue;
		addr = show_addr(source, ch);
		if (addr != NULL)
		{
			printf("The same char is %c and it's address is %p\n", *addr, addr);
		}
		else
			printf("Same char not found.\n");
	}

	while (true);
	return 0;
}

char *show_addr(char *str1, char ch)
{
	for (int i = 0; i < 21; i++)
	{
		if (ch == str1[i])
			return &str1[i];
	}
	return NULL;
}
