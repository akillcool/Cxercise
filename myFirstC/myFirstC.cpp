//PE 11-5 no loop
#include <stdio.h>
#include <stdbool.h>

bool is_within(char ch, const char *str);

int main(void)
{
	char str[81];
	char ch;

	printf("Please input a string: \n");
	gets_s(str);
	printf("Please input a char: \n");
	ch = getchar();
	if (is_within(ch, str))
		printf("The char is in the string.\n");
	else
		printf("The char is not in the string.\n");

	while (true);
	return 0;
}

bool is_within(char ch, const char *str)
{
	for (int i = 0; i < 81; i++)
	{
		if (ch == str[i])
			return true;
	}
	return false;
}