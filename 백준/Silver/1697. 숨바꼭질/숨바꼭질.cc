#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int x, k, INF = 100000000;
int mins[100001];
vector<pair<int, int>> graph[100001];


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

		for (int next : {current * 2, current - 1, current + 1})
		{
			if (next < 0 || next > 100000) continue;
			int nextDistance = 1 + distance;

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

	cin >> x >> k;

	fill(mins, mins + 100001, INF);
	mins[x] = 0;

	if (x <= k)
	{
		Dijkstar(x);
		cout << mins[k];
	}
	else
		cout << x - k;
}