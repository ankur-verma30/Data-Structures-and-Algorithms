#include <bits/stdc++.h>
#define I INT_MAX

using namespace std;

int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                   {2, 6, 3, 7, 4, 5, 7, 6, 7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};

int sets[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int include[9] = {0};
int t[2][6];

void Union(int u, int v)
{
    if (sets[u] < sets[v])
    {
        sets[u] += sets[v];
        sets[v] = u;
    }
    else
    {
        sets[v] += sets[u];
        sets[u] = v;
    }
}

int find(int u)
{
    int x = u, v = 0;

    while (sets[x] > 0)
    {
        x = sets[x];
    }
    while (u != x)
    {
        v = sets[u];
        sets[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int i = 0, n = 7, e = 9, min, u, v, k;

    while (i < n - 1)
    {
        min = I;
        for (int j = 0; j < e; j++)
        {
            if (include[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        if (find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;

            Union(find(u), find(v));
            i++;
        }
        include[k] = 1;
    }

    for (int i = 0; i < n - 1; i++)
        cout << " ( " << t[0][i] << " , " << t[1][i] << " ) " << endl;

    return 0;
}