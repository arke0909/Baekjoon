#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, INF = 10000000, result = 10000000, idx = -1;
int graph[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
				graph[i][j] = INF;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;

		graph[start - 1][end - 1] = 1;
		graph[end - 1][start - 1] = 1;
	}


	// 거쳐갈 정점
	for (int i = 0; i < n; ++i)
		// 출발할 정점
		for (int j = 0; j < n; ++j)
			// 도착할 정점
			for (int k = 0; k < n; ++k)
			{
				// 거쳐갈 정점이 출발할 정점이라면 넘기기
				if (i == j) continue;

				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}

	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			cnt += graph[i][j];
		}

		if (result > cnt)
		{
			result = cnt;
			idx = i + 1;
		}
	}

	cout << idx;
}
