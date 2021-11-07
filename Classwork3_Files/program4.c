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

	sum++;
	fseek(f, 0, SEEK_SET);

	int maxm = 0;
	int max = 0;
	for(int i = 0; i < sum; i++)
	{	
		max = 0;
		while (1)
		{
			int c = fgetc(f);
			if (c == EOF || c == 10)
				break;

			max++;
		}	
		if(max > maxm)
			maxm = max;
	}
	printf("%d", maxm);
	fclose(f);

}