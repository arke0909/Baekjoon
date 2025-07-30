#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, INF = 100000000, mins[1000];
vector<pair<int, int>> graph[1000];
vector<int> citys[1000];

void Dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	mins[start] = 0;
	citys[start].push_back(start + 1);

	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int current = pq.top().second;

		pq.pop();

		if (curDist > mins[current]) continue;

		for (int i = 0; i < graph[current].size(); ++i)
		{
			int nextDistance = graph[current][i].first + curDist;
			int next = graph[current][i].second;

			if (mins[next] > nextDistance)
			{
				citys[next] = citys[current];
				citys[next].push_back(next + 1);
				mins[next] = nextDistance;
				pq.push({ nextDistance, next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	fill(mins, mins + 1000, INF);

	for (int i = 0; i < m; ++i)
	{
		int start, end, distance;
		cin >> start >> end >> distance;

		graph[start - 1].push_back({ distance, end - 1 });
	}

	int s, e;
	cin >> s >> e;

	Dijkstra(s - 1);

	cout << mins[e - 1] << '\n' << citys[e - 1].size() << '\n';
	for (auto item : citys[e - 1])
		cout << item << ' ';
}