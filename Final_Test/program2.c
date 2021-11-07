#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char st[1000000];
	scanf("%s", st);
	int length = strlen(st);
	int sum = 0;
	for(int i = 0; i < length; i++)
	{
		int el;
		el = st[i] - '0';
		if(i % 2 == 0)
			sum = sum + el;
		else
			sum = sum - el;
	}
	if(sum % 11 == 0)
		printf("YES");
	else
		printf("NO");

}