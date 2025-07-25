#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, origin;
vector<int>* graph;
bool* isVisited_DFS;
bool* isVisited_BFS;

void DFS(int start)
{
	cout << start + 1 << ' ';
	isVisited_DFS[start] = true;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		int y = graph[start][i];

		if (!isVisited_DFS[y])
			DFS(y);
	}
}

void BFS(int start)
{
	queue<int> q;

	q.push(start);

	while (!q.empty())
	{
		int y = q.front();
		q.pop();

		if (isVisited_BFS[y]) continue;
		isVisited_BFS[y] = true;
		cout << y + 1 << ' ';

		for (auto item : graph[y])
		{
			q.push(item);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> origin;

	graph = new vector<int>[n];
	isVisited_DFS = new bool[n] {false};
	isVisited_BFS = new bool[n] {false};

	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;

		graph[start - 1].push_back(end - 1);
		graph[end - 1].push_back(start - 1);
	}

	for (int i = 0; i < n; ++i)
		sort(graph[i].begin(), graph[i].end());

	DFS(origin - 1);
	cout << '\n';
	BFS(origin - 1);
}