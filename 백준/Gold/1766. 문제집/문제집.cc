#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, root[32000];
vector<int> graph[32000], save;

void TopologySort()
{
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; ++i)
	{
		if (root[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int v = q.top();
		q.pop();

		save.push_back(v + 1);

		for (int i = 0; i < graph[v].size(); ++i)
		{
			root[graph[v][i]]--;
			if (root[graph[v][i]] == 0)
				q.push(graph[v][i]);

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;
		graph[start - 1].push_back(end - 1);
		root[end - 1]++;
	}

	TopologySort();

	for (auto item : save)
		cout << item << ' ';
}


