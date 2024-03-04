#include <bits/stdc++.h>

using namespace std;

int main()
{
    int matrix_size;
    cout << "the number of elements in the graph ";
    cin >> matrix_size;
    int graph[matrix_size + 1][matrix_size + 1];

    for (int i = 0; i < matrix_size + 1; i++){
        for (int j = 0; j < matrix_size + 1; j++){
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < matrix_size+1; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "the adjcency matrix is " << endl;

    for (int i = 0; i < matrix_size + 1; i++){
        for (int j = 0; j < matrix_size + 1; j++){
            cout << " " << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}