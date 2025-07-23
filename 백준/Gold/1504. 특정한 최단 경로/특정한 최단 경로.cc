#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, e, INF = 100000000;
int mins1[801];
int mins2[801];
int mins3[801];
vector<pair<int, int>> graph[801];


void Dijkstar(int start, int mins[])
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, start });

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = pq.top().first;

		pq.pop();

		if (mins[current] < distance) continue;

		for (int i = 0; i < graph[current].size(); ++i)
		{
			int next = graph[current][i].second;
			int nextDistance = graph[current][i].first + distance;

			if (mins[next] > nextDistance)
			{
				mins[next] = nextDistance;
				pq.push({ nextDistance, next });
			}

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v1, v2;
	cin >> n >> e;

	fill(mins1, mins1 + n + 1, INF);
	fill(mins2, mins2 + n + 1, INF);
	fill(mins3, mins3 + n + 1, INF);

	for (int i = 0; i < e; ++i)
	{
		int start, end, length;
		cin >> start >> end >> length;
		graph[start].push_back({ length, end });
		graph[end].push_back({ length, start });
	}
	cin >> v1 >> v2;

	mins1[1] = 0;
	mins2[v1] = 0;
	mins3[v2] = 0;

	Dijkstar(1, mins1);
	Dijkstar(v1, mins2);
	Dijkstar(v2, mins3);

	int path1 = mins1[v1] + mins2[v2] + mins3[n];
	int path2 = mins1[v2] + mins3[v1] + mins2[n];
	int answer;

	if (path1 != INF || path2 != INF)
		answer = min(path1, path2);

	if (answer >= INF)
		cout << -1;
	else
		cout << answer;

}