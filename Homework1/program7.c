#include <stdio.h>
#include <math.h>

unsigned long long fact(unsigned long long x, unsigned long long y)
{
    unsigned long long fact = 1;
    unsigned long long delt = x - y +1;

    for(int i=delt; i<=x; i++)
    {
        fact = fact * i; 
    }     

    return fact;
}

int main()
{     
    unsigned long long n, k, a;

    scanf("%llu %llu", &n, &k);

    a = fact(n, k);

    printf("%llu", a);
}