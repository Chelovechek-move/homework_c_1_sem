#include <stdio.h>

int main()
{
	int c = 0;
	FILE* f = fopen("test.txt", "r");

	fseek(f, -3, SEEK_END);
	c = fgetc(f);
	printf("%c", c);

	fseek(f, -2, SEEK_END);
	c = fgetc(f);
	printf("%c", c);

	fseek(f, -1, SEEK_END);
	c = fgetc(f);
	printf("%c", c);

	fclose(f);
}