#include <stdio.h>
#include <math.h>

int main()
{ 
    
    int n, j;  

    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)

            printf("%d ", i * j);

            if(j % 10 == 0)
                printf("\n");
    }
}