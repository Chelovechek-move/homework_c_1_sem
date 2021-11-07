#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c = 0;
    int sum;

    FILE* f = fopen("test.txt", "r");
	while (1)
	{
		int c = fgetc(f);
		if (c == EOF)
		break;

		if(c == 10)
			sum++;
	}

	printf("%d", sum + 1);
	fclose(f);

}