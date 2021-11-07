#include <stdio.h>
#include <math.h>

unsigned long long sum(unsigned long long x, unsigned long long y)
{
    unsigned long long k = x * y;
    return k;
}

int main()
{     
    unsigned long long a, b, ans;

    scanf("%llu %llu", &a, &b);

    ans = sum(a, b);

    printf("%llu", ans);
}