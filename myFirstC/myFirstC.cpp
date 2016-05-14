// myFirstC.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#define MONTHS 12    /* number of months in a year */
#define YRS   5      /* number of years of data    */

int main(void)
{
		/* initializing rainfall data for 1990 - 1994 */
		const float rain[YRS][MONTHS] = {
			{ 10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4 },
			{ 9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2 },
			{ 6.6, 5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2 },
			{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
			{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2 }
		};
		int year, month;
		float subtot, total;

		printf(" YEAR    RAINFALL  (inches)\n");
		for (year = 0, total = 0; year < YRS; year++)
		{             /* for each year, sum rainfall for each month */
			for (month = 0, subtot = 0; month < MONTHS; month++)
				subtot += *(*(rain + year) + month);
				//subtot += rain[year][month];
			printf("%5d %15.1f\n", 1990 + year, subtot);
			total += subtot;                  /* total for all years */
		}
		printf("\nThe yearly average is %.1f inches.\n\n", total / YRS);
		printf("MONTHLY AVERAGES:\n\n");
		printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
		printf(" Nov  Dec\n");

		for (month = 0; month < MONTHS; month++)
		{               /* for each month, sum rainfall over years */
			for (year = 0, subtot = 0; year < YRS; year++)
				subtot += *(*(rain + year) + month);
				//subtot += rain[year][month];
			printf("%4.1f ", subtot / YRS);
		}
		printf("\n");


	while (true);
	return 0;
}
