#include <stdio.h>
int factorial(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
        f = f * i;
    return f;
}
int c(int n, int r)
{
    int t1, t2, t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n - r);
    return t1 / (t2 * t3);
}
int main()
{
    int n, r;
    double comb = 0;
    printf("For combination give n and r");
    scanf("%d %d", &n, &r);
    comb = c(n, r);
    printf("The value of nCr = %lf ", comb);
}