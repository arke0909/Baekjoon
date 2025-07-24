#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, target, cnt = 0;
bool* isVisited;
vector<int>* graph;

void DFS(int x)
{
	if (x == target) return;
	bool flag = false;
	isVisited[x] = true;

	for (int i = 0; i < graph[x].size(); ++i)
	{
		int y = graph[x][i];

		if (isVisited[y] || y == target)
		{
			continue;
		}

		DFS(y);
		flag = true;
	}

	if (!flag)
		cnt++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start;
	cin >> n;
	graph = new vector<int>[n];
	isVisited = new bool[n] {false};

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;

		if (v == -1)
		{
			start = i;
			continue;
		}
		graph[v].push_back(i);
	}

	cin >> target;

	DFS(start);
	cout << cnt;
}