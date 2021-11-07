#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Error!\n");
		printf("To use this program: a <name of the file>\n");
		exit(1);
	}

	char filename[20];
	sscanf(argv[1], "%s", &filename);

	int c;
	int i1, i2;
	FILE* f = fopen(filename, "r");

	fseek(f, 0, SEEK_SET);
	i1 = ftell(f);

	fseek(f, -1, SEEK_END);
	i2 = ftell(f);

	printf("%d", i2 - i1);
	
	fclose(f);
}