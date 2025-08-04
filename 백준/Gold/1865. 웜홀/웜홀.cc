#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int t, n, m, w, INF = 100000000;
vector<pair<int, int>> graph[501];
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

				if (mins[next] > mins[j] + cost)
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

	cin >> t;

	while (t--)
	{
		cycle = false;

		cin >> n >> m >> w;

		fill(mins + 1, mins + n + 1, INF);
		for (int i = 1; i <= n; ++i) graph[i].clear();
		mins[1] = 0;

		for (int i = 1; i <= m; ++i)
		{
			int start, end, cost;
			cin >> start >> end >> cost;

			graph[start].push_back({ end ,cost });
			graph[end].push_back({ start ,cost });
		}

		for (int i = 1; i <= w; ++i)
		{
			int start, end, cost;
			cin >> start >> end >> cost;

			graph[start].push_back({ end ,-cost });
		}

		BF();

		if (!cycle)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
}
