#include <stdio.h>
#include <math.h>

void fib(unsigned long long x)
{
    unsigned long long f0 = 0;
    unsigned long long f1 = 1;
    unsigned long long sum = 0;

    if(x == 1)
        sum = 1;

    for(int i=2; i<=x; i++)
    {

        sum = f0 + f1;

        f0 = f1;
        f1 = sum;

        if(f0 / 10 != 0)
            f0 = f0 % 10;

        if(f1 / 10 != 0)
            f1 = f1 % 10;
    }     

    if(sum / 10 != 0)
        printf("%llu", sum % 10);
    else 
        printf("%llu", sum);
}

int main()
{     
    unsigned long long n, k, a;

    scanf("%llu", &n);

    fib(n);
}