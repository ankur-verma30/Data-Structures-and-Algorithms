#include <stdio.h>
struct matrix
{
    int A[10];
    int n;
};
void set(struct matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}
int get(struct matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    return 0;
}
void display(struct matrix m)
{

    for (int i = 1; i <= m.n; ++i)
    {
        for (int j = 1; j <= m.n; ++j) // idk why it is not running when starting with zero
        {
            if (i == j)
                printf("%d ", m.A[i - 1]); // The A array has a size of 10, which means that valid indices are from 0 to 9. When i and j are both 0, the first iteration of the loop will access m.A[-1], which is outside the bounds of the array and may result in undefined behavior (i.e., the program may crash, produce incorrect results, or behave unpredictably).
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    m.n = 4;
    set(&m, 1, 1, 5);
    set(&m, 2, 2, 8);
    set(&m, 3, 3, 9);
    set(&m, 4, 4, 12);
    display(m);
    return 0;
}