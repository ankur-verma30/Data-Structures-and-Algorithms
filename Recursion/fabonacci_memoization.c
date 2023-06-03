#include <stdio.h>
int F[100];
int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {

        F[n - 2] == -1;
        F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);
        return F[n - 1] + F[n - 2];
    }
}
int main()
{
    for (int i = 0; i < 100; i++)
        F[i] = -1;
    printf("%d\n", mfib(5));
    return 0;
}