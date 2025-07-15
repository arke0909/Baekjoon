#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool** isVisited;
int** graph;
int n, m, X[4] = { -1, 0, 1, 0 }, Y[4] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{

	if (y < 0 || y >= m || x < 0 || x >= n) return;
	if (graph[y][x] == 0 || isVisited[y][x]) return;

	isVisited[y][x] = true;
	graph[y][x] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nextY = y + Y[i];
		int nextX = x + X[i];

		dfs(nextY, nextX);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int k, cnt = 0;
		cin >> n >> m >> k;

		isVisited = new bool* [m];
		graph = new int* [m];

		for (int j = 0; j < m; ++j)
			isVisited[j] = new bool[n] {false};
		for (int j = 0; j < m; ++j)
			graph[j] = new int[n] {0};

		for (int j = 0; j < k; ++j)
		{
			int x, y;
			cin >> x >> y;
			graph[y][x] = 1;
		}

		for (int j = 0; j < m; ++j)
		{
			for (int l = 0; l < n; ++l)
			{
				if (graph[j][l] == 1)
				{
					dfs(j, l);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';

		for (int j = 0; j < m; ++j)
		{
			delete[] isVisited[j];
			delete[] graph[j];
		}
		delete[] isVisited;
		delete[] graph;
	}
}
