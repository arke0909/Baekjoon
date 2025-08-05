#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, from, to, m, money[51];
vector<pair<int, int>> graph[51];
long long mins[51], INF = -5000000000000;
bool cycle = false, isVisited[51];

bool BFS(int start)
{
	queue<int> q;
	fill(isVisited, isVisited + n, false);
	isVisited[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;

			if (next == to) return true;

			if (!isVisited[next])
			{
				isVisited[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

void BF(int start)
{
	mins[start] = money[start];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < graph[j].size(); ++k)
			{
				int next = graph[j][k].first;
				int cost = graph[j][k].second;

				if (mins[j] != INF && mins[next] < mins[j] + cost + money[next])
				{
					if (i == n)
					{
						if (BFS(j)) cycle = true;
					}
					else
						mins[next] = mins[j] + cost + money[next];
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> from >> to >> m;
	fill(mins, mins + n, INF);

	for (int i = 0; i < m; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end , -cost });
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> money[i];
	}

	BF(from);

	if (mins[to] == INF)
		cout << "gg";
	else if (cycle)
		cout << "Gee";
	else
		cout << mins[to];

	return 0;
}
