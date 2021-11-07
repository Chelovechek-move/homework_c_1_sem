#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	scanf("%d", &n);

	double* mas = (double*)malloc(n * sizeof(double));
	double sum = 0.0;
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &mas[i]);
		sum = sum + mas[i];
	}

	double middle = sum / n;

	for(int i = 0; i < n; i++)
		printf("%.4lf ", mas[i] - middle);
	free(mas);

}
