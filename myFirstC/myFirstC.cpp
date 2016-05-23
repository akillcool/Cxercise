/* Programming Exercise 11-13 */
#include <stdio.h>
#include <stdlib.h>        /* for atof()           */
#include <math.h>        /* for pow()            */
/* #include <console.h> */   /* Macintosh adjustment */
int main(int argc, char *argv[])
{
	double num;
	int exp;

	/* argc = ccommand(&argv); */  /* Macintosh adjustment */
	if (argc != 3)
		printf("Usage: %s number exponent\n", argv[0]);
	else
	{
		num = atof(argv[1]);
		exp = atoi(argv[2]);
		printf("%.2f to the %d power = %g\n", num, exp, pow(num, exp));
	}
	
	while (true);
	return 0;
}

