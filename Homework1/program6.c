#include <stdio.h>
#include <math.h>

unsigned long long fact(unsigned long long x)
{
    unsigned long long k = 1;

    for(int i=1; i<=x; i++)
    {
        k = k * i; 
    }     

    return k;
}

int main()
{     
    unsigned long long n, a;

    scanf("%llu", &n);

    a = fact(n);

    printf("%llu", a);
}