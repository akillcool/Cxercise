#include <stdio.h>
void reverse(char *p);
int main(void)
{
	char str[81];
	do
	{
		puts("input a string:");
		gets_s(str);
		reverse(str);
		puts(str);
		puts("input any char except q to go on.");
		gets_s(str);
	} while (*str != 'q');
	puts("Quit.");
	return 0;
}

void reverse(char *p)
{
	int i, n;
	char temp;
	for (n = 0; *(p + n) != '\0'; n++) 
		continue;
	n--;
	for (i = 0; i < n - i; i++)
	{
		temp = p[i];
		p[i] = p[n - i];
		p[n - i] = temp;
	}
}