#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, INF = 10000000, result = 0, mins_whenGo[1000], mins_whenBack[1000];
vector<pair<int, int>>* graph;

void dijkstra_whenGo(int idx)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;


	mins_whenGo[idx] = 0;
	pq.push({ 0, idx });

	while (!pq.empty())
	{
		int distance = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int nextDistance = graph[cur][i].first + distance;
			int next = graph[cur][i].second;

			if (nextDistance > mins_whenGo[next]) continue;

			mins_whenGo[next] = nextDistance;
			pq.push({ nextDistance, next });
		}
	}
}

void dijkstra_whenBack(int idx)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;


	mins_whenBack[idx] = 0;
	pq.push({ 0, idx });

	while (!pq.empty())
	{
		int distance = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int nextDistance = graph[cur][i].first + distance;
			int next = graph[cur][i].second;

			if (nextDistance > mins_whenBack[next]) continue;

			mins_whenBack[next] = nextDistance;
			pq.push({ nextDistance, next });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;

	graph = new vector<pair<int, int>>[n];

	for (int i = 0; i < m; ++i)
	{
		int start, end, t;
		cin >> start >> end >> t;

		graph[start - 1].push_back({ t, end - 1 });
	}

	fill(mins_whenBack, mins_whenBack + n, INF);

	dijkstra_whenBack(x - 1);

	for (int i = 0; i < n; ++i)
	{
		if (i == x - 1) continue;

		fill(mins_whenGo, mins_whenGo + n, INF);

		dijkstra_whenGo(i);

		result = max(result, mins_whenGo[x - 1] + mins_whenBack[i]);
	}

	cout << result;
}