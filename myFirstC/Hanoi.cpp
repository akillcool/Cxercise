//13.10.4
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int count = 0;
	double num;
	double total = 0;

	if (argc == 1)
	{
		fp = stdin;
	}
	else if (argc == 2)
	{
		if ((fp = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Failed to open %s.\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s filename",argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("Now input numbers: (q to quit)\n");
	while ((fscanf(fp,"%lf", &num)) == 1)
	{
		total += num;
		count++;
	}
	printf("The average number of your input is %.2f.\n", total / count);

	return 0;
}



