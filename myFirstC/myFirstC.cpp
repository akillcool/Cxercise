#include <stdio.h>
#include <string.h>

void show_src(char **p, int n);
void show_ascii(char **p, int n);
void show_length(char **p, int n);
void show_word(char **p, int n);

int main(void)
{
	char str[10][81];
	char *p[10];
	int ct = 0;
	int selection;

	while (ct != 10)
	{
		printf("Please input string %d, use Ctrl+Z to quit: \n", ct + 1);
		if (gets_s(str[ct]) != NULL)
			p[ct] = str[ct];
		else
			break;
		ct++;
	}
	puts("Make selection from follows.");
	puts("1.print				2.print in ASCII sequence");
	puts("3.print in length		4.print in first word's sequence");
	puts("5.quit");
	while ((scanf_s("%d", &selection)) == 1 && selection > 0 && selection < 6)
	{
		switch (selection)
		{
		case 1:show_src(p, ct);
			break;
		case 2:show_ascii(p, ct);
			break;
		case 3:show_length(p, ct);
			break;
		case 4:show_word(p, ct);
			break;
		case 5:return 0;
		}
	}

	while (true);
	return 0;
}

void show_src(char **p, int n)
{
	for (int i = 0; i < n; i++)
	{
		puts(p[i]);
	}
}

void show_ascii(char **p, int n)
{
	char *temp;

	for (int top = 0; top < n - 1; top++)
	{
		for (int seek = top + 1; seek < n; seek++)
		{
			if (strcmp(p[top], p[seek]) > 0)
			{
				temp = p[top];
				p[top] = p[seek];
				p[seek] = temp;
			}
		}
	}
	show_src(p, n);
}

void show_length(char **p, int n)
{
	char *temp;

	for (int top = 0; top < n - 1; top++)
	{
		for (int seek = top + 1; seek < n; seek++)
		{
			if (strlen(p[top]) > strlen(p[seek]))
			{
				temp = p[top];
				p[top] = p[seek];
				p[seek] = temp;
			}
		}
	}
	show_src(p, n);
}

void show_word(char **p, int n)
{
	char *temp;
	char *pos1, *pos2;

	for (int top = 0; top < n - 1; top++)
	{
		for (int seek = top + 1; seek < n; seek++)
		{
			pos1 = p[top];
			while (*pos1 != ' ' && *pos1 != '\0')
			{
				pos1++;
			}
			pos2 = p[seek];
			while (*pos2 != ' ' && *pos2 != '\0')
			{
				pos2++;
			}
			if (pos1 - p[top] > pos2 - p[seek])
			{
				temp = p[top];
				p[top] = p[seek];
				p[seek] = temp;
			}
		}
	}
	show_src(p, n);
}