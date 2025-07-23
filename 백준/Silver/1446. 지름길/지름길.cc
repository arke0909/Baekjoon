#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, d, INF = 100000000;
int mins[10001];
vector<pair<int, int>> graph[10001];


void Dijkstar(int start)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;

		pq.pop();

		if (mins[current] < distance) continue;

		for (int i = 0; i < graph[current].size(); ++i)
		{
			int next = graph[current][i].first;
			int nextDistance = graph[current][i].second + distance;

			if (mins[next] > nextDistance)
			{
				mins[next] = nextDistance;
				pq.push({ next, -nextDistance });
			}

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> d;

	fill(mins, mins + d + 1, INF);

	for (int i = 0; i < d; ++i)
		graph[i].push_back({ i + 1, 1 });

	for (int i = 0; i < n; ++i)
	{
		int start, end, length;
		cin >> start >> end >> length;
		if (end > d) continue;
		graph[start].push_back({ end, length });
	}

	mins[0] = 0;
	Dijkstar(0);

	cout << mins[d];
}