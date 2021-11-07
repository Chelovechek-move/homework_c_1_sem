#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	FILE* file = fopen("test.txt", "r");
	if (errno == ENOENT)
	{
		printf("The file does not exist");
		exit(1);
	}
	else
	{
		printf("File exists");
	}
	
	fclose(file);
}
