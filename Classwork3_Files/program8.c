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
		if(c != 32 && (c < 48 || c > 57) && c != -1)
		{
			printf("Error!");
			exit(1);
		}
		if (c == EOF)
		break;

		if(c == 32)
			sum++;		
	}
	printf("%d\n", sum);


	int kolnum = sum + 1;

	int* arr = (int*)malloc(kolnum * sizeof(int));
	for(int i = 0; i < kolnum; i++)
		arr[i] = 0;


	fseek(f, 0, SEEK_SET);

	int a = 0;

	for(int i = 0; i < kolnum; i++)
	{
		fscanf(f, "%d", &a);
		arr[i] = a;
	}

	
	for(int i = 0; i < kolnum; i++)
		printf("%d ", arr[i]);

	fclose(f);
	free(arr);

}