#include <stdio.h>
#include <ctype.h>

//void non_space(char *);
void drop_space(char * s);

int main(void)
{
	char str[181];

	printf("Please input a string: \n");
	while (gets_s(str) && *str != '\0')
	{
		//non_space(str);
		drop_space(str);
		puts(str);
		printf("Please input another string, enter to quit. \n");
	}

	while (true);
	return 0;
}

//void non_space(char *str)
//{
//	int n, i, j;
//	int ct = 0;		//count space
//
//	for (n = 0; *(str + n) != '\0'; n++)	//tell the length of string
//	{
//		continue;
//	}
//
//	for (i = 0; i < n - ct; i++)
//	{
//		if (isspace(str[i]))
//		{
//			ct++;
//			for ( j = i; str[j + 1] != '\0'; j++)
//			{
//				str[j] = str[j + 1];
//			}
//		}
//	}
//	str[n - ct] = '\0';
//}

void drop_space(char * s)
{
	int ct = 0;
	char * pos;
	while (*s)     /* or while (*s != '\0') */
	{
		if (*s == ' ')
		{
			pos = s;
			do
			{
				*pos = *(pos + 1);
				pos++;
			} while (*pos);
		}
		else
			s++;
	}

}
