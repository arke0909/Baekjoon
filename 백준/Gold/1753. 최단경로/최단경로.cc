#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int v, e, INF = 100000000;
int mins[20001];
vector<pair<int, int>> graph[20001];


void Dijkstar(int start)
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

	int start;
	cin >> v >> e >> start;

	fill(mins, mins + v + 1, INF);

	for (int i = 0; i < e; ++i)
	{
		int start, end, length;
		cin >> start >> end >> length;
		graph[start].push_back({ length, end });
	}

	mins[start] = 0;
	Dijkstar(start);

	for (int i = 1; i <= v; ++i)
	{
		if(mins[i] != INF)
			cout << mins[i] << '\n';
		else
			cout << "INF\n";
	}
}