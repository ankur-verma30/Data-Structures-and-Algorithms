#include <stdio.h>
#include "Queue.h"

void BreadthFirstSearch(int G[][7], int start, int n)
{
    int i = start;
    int visited[7] = {0};

    printf("%d ", i);
    visited[i] = 1;

    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (int j = 1; j < n; j++)
        {
            if (visited[j] == 0 && G[i][j] == 1)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DepthFirstSearch(int G[][7], int start, int n)
{
    int i = start;
    static int visited[7] = {0};

    if (visited[i] == 0)
    {
        printf("%d ", i);
        visited[i] = 1;

        for (int j = 1; j < n; j++)
        {
            if (G[j][i] == 1 && visited[j] == 0)
            {
                DepthFirstSearch(G, j, n);
            }
        }
    }
}

int main()
{
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("The Breadth first Search of the graph is \n");
    BreadthFirstSearch(G, 5, 7);
    printf("\nThe Depth first Search of the graph is \n");

    DepthFirstSearch(G, 5, 7);

    return 0;
}