#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2147483647;
int length[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, start, end, cost;
	vector<vector<pair<int, int>>> nodes(50001);

	cin >> n >> m;

	fill(length, length + n + 1, INF);

	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> cost;

		nodes[start].push_back({ cost,end });
		nodes[end].push_back({ cost, start });
	}

	length[1] = 0;
	q.push({ 0, 1 });

	while (!q.empty())
	{
		int curCost = q.top().first;
		int curNode = q.top().second;
		q.pop();

		for (auto item : nodes[curNode])
		{
			int nc = curCost + item.first;

			if (nc < length[item.second])
			{
				length[item.second] = nc;
				q.push({ nc,item.second});
			}
		}
	}

	cout << length[n];
}
