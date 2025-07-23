#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int city, bus, INF = 100000000;
int mins[1001];
vector<pair<int, int>> graph[1001];


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

	int start, end;
	cin >> city >> bus;

	fill(mins, mins + city + 1, INF);

	for (int i = 0; i < bus; ++i)
	{
		int start, end, length;
		cin >> start >> end >> length;
		graph[start].push_back({ length, end });
	}

	cin >> start >> end;

	mins[start] = 0;
	Dijkstar(start);

	cout << mins[end];
}