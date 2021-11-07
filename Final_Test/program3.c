#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game
{
	char name[31];
	int k;
	int mas[1000002];
};
typedef struct game Game;

int main()
{
	int n;
	scanf("%d", &n);

	Game* list = (Game*)malloc(n * sizeof(Game));
	int i = 0;
	for(i = 0; i < n; i++);
	{
		int k;
		scanf("%[^ ]", &list[i].name);
		scanf("%d", &k);

		for(int j = 0; j < k; j++)
			scanf("%d", &list[i].mas[j]);
	}

	for(i = 0; i < n; i++);
	{
		int k;
		printf("%s ", list[i].name);
		printf("%d ", k);

		for(int j = 0; j < k; j++)
			printf("%d ", list[i].mas[j]);
		printf("\n");
	}



	free(list);
}