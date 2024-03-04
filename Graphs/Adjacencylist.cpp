#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cout << "the number of elements in the graph ";
    cin >> n >> m;
    vector<int> graph[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "the adjcency List is " << endl;

    int len = graph[0].size();
    for (int i = 0; i < len; i++)
        cout << graph[0][i] << " ";

    return 0;
}