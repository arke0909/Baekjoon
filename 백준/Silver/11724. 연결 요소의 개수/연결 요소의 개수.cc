#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>* graph;
bool* isVisited;
int cnt = 0;

void dfs(int x)
{
	isVisited[x] = true;

	for (int i = 0; i < graph[x].size(); ++i)
	{
		int y = graph[x][i];

		if (!isVisited[y])
		{
			cnt--;
			dfs(y);
		}
	}  
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m = 0;
	cin >> n >> m;

	graph = new vector<int>[n];
	isVisited = new bool[n] {false};
	cnt = n;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}

	for (int i = 0; i < n; ++i)
		dfs(i);

	cout << cnt;
}
