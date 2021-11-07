#include <stdio.h>

int main()
{
	FILE* f = fopen("sail.txt", "r");
	while (1)
	{
		int c = fgetc(f);
		if (c == EOF)
		break;
		printf("%c", c);
	}

	fclose(f);
}