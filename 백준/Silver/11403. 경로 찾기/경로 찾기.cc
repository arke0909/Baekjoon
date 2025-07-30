#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, INF = 10000000;
int graph[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) 
        {
            cin >> graph[i][j];

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(graph[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << 1 << ' ';
        }
        cout << '\n';
    }
}
