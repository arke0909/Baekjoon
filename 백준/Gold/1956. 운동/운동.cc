#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, INF = 10000000, result = INF;
int graph[401][401];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i != j)
				graph[i][j] = INF;
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start][end] = cost;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
			{
				if (i == j) continue;

				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j) continue;

			result = min(result, graph[i][j] + graph[j][i]);
		}
	}

	if(result == INF)
		cout << -1;
	else
		cout << result;
}
