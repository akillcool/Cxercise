/* Programming Exercise 11-7 */
#include <stdio.h>
#define LEN 20
char * string_in(const char * s1, const char * s2);
int main(void)
{
	char orig[LEN] = "transportation";
	char * find;

	puts(orig);
	find = string_in(orig, "port");
	if (find)
		puts(find);
	else
		puts("Not found");
	find = string_in(orig, "part");
	if (find)
		puts(find);
	else
		puts("Not found");

	while (true);
	return 0;
}

#include <string.h>
char * string_in(const char * s1, const char * s2)
{
	int l2 = strlen(s2);
	int tries;            /* maximum number of comparisons    */
	int nomatch = 1;    /* set to 0 if match is found        */

	tries = strlen(s1) + 1 - l2;
	if (tries > 0)
		while ((nomatch = strncmp(s1, s2, l2)) && tries--)
			s1++;
	if (nomatch)
		return NULL;
	else
		return (char *)s1;  /* cast const away */
}

