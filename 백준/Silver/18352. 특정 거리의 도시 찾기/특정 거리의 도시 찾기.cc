#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int k, INF = 1000000000;
int* values;
vector<pair<int, int>>* graph;

void Dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ start - 1, 0 });
	values[start - 1] = 0;

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = pq.top().second;

		pq.pop();

		if (values[current] < distance) continue;

		for (int i = 0; i < graph[current].size(); ++i)
		{
			int next = graph[current][i].first;
			int nextDistance = distance + graph[current][i].second;

			if (values[next] > nextDistance)
			{
				values[next] = nextDistance;
				pq.push({ next, nextDistance });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x;
	bool flag = false;
	cin >> n >> m >> k >> x;

	graph = new vector<pair<int, int>>[n];
	values = new int[n];
	fill(values, values + n, INF);

	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;

		graph[start - 1].push_back({ end - 1, 1 });
	}

	Dijkstra(x);

	for (int i = 0; i < n; ++i)
	{
		if (k == values[i])
		{
			cout << i + 1 << '\n';
			flag = true;
		}
	}
	if (!flag)
		cout << -1;
}