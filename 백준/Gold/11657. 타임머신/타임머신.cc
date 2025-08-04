#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, INF = 10000000;
vector<pair<int,int>> graph[501];
long long mins[501];
bool cycle = false;

void BF()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 0; k < graph[j].size(); ++k)
			{
				int next = graph[j][k].first;
				int cost = graph[j][k].second;

				if (mins[j] != INF && mins[next] > mins[j] + cost)
				{
					mins[next] = mins[j] + cost;
					if (i == n) cycle = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	fill(mins + 1, mins + n + 1, INF);
	mins[1] = 0;

	for (int i = 1; i <= m; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start].push_back({ end ,cost });
	}

	BF();
	
	if (!cycle)
	{
		for (int i = 2; i <= n; ++i)
		{
			int v = mins[i];

			if (mins[i] != INF)
				cout << mins[i] << '\n';
			else
				cout << -1 << '\n';
		}
	}
	else
	{
		cout << -1;
	}
}
