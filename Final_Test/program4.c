#include <stdio.h>
#include <stdlib.h>

struct day
{
	char name[4];
};
typedef struct day Day;

int get_value(char str[])
{
	int a = 0;

	if(str[0] == 'M')
		a = 1;
	if(str[0] == 'W')
		a = 3;
	if(str[0] == 'T')
	{
		if(str[1] == 'u')
			a = 2;
		else
			a = 4;
	}
	if(str[0] == 'F')
		a = 5;
	if(str[0] == 'S')
	{
		if(str[1] == 'a')
			a = 6;
		else 
			a = 7;
	}
	
	return a;
}

void quicksort(Day* array, int lo, int hi)
{
	if (hi - lo > 1)
	{
		Day pivot = array[hi - 1];
		int j = lo;
		for (int i = lo; i < hi; i++)
			if (get_value(array[i].name) <= get_value(pivot.name))
			{
				Day temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				j++;
			}
		int j1 = j;
		j = lo;

		for (int i = lo; i < j1; i++)
		{
			

			if (get_value(array[i].name) < get_value(pivot.name))
			{
				Day temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				j++;
			}
		}

		quicksort(array, lo, j);
		quicksort(array, j1, hi);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	Day* mas = (Day*)malloc(n * sizeof(Day));
	for(int i = 0; i < n; i++)
		scanf("%s", mas[i].name);

	quicksort(mas, 0, n);
	for(int i = 0; i < n; i++)
		printf("%s ", mas[i].name);
	free(mas);
}