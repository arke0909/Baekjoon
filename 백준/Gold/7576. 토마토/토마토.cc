#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt = 0;
int** graph;
int** days;
bool** isVisited_BFS;
bool** isFixed;
queue<pair<int, int>> q;

void BFS()
{
	int day = 0;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (curX < 0 || curX >= n || curY < 0 || curY >= m) continue;

		if (isVisited_BFS[curY][curX]) continue;
		isVisited_BFS[curY][curX] = true;

		if (graph[curY][curX] == -1) continue;
		graph[curY][curX] = 1;

		int nextDay = days[curY][curX] + 1;

		if (curX + 1 < n && !isVisited_BFS[curY][curX + 1] && graph[curY][curX + 1] == 0 && !isFixed[curY][curX + 1])
		{
			days[curY][curX + 1] = nextDay;
			isFixed[curY][curX + 1] = true;
		}
		if (curX - 1 >= 0 && !isVisited_BFS[curY][curX - 1] && graph[curY][curX - 1] == 0 && !isFixed[curY][curX - 1])
		{
			days[curY][curX - 1] = nextDay;
			isFixed[curY][curX - 1] = true;

		}
		if (curY + 1 < m && !isVisited_BFS[curY + 1][curX] && graph[curY + 1][curX] == 0 && !isFixed[curY + 1][curX])
		{
			days[curY + 1][curX] = nextDay;

			isFixed[curY + 1][curX] = true;
		}
		if (curY - 1 >= 0 && !isVisited_BFS[curY - 1][curX] && graph[curY - 1][curX] == 0 && !isFixed[curY - 1][curX])
		{
			days[curY - 1][curX] = nextDay;
			isFixed[curY - 1][curX] = true;

		}

		q.push({ curX + 1, curY });
		q.push({ curX - 1, curY });
		q.push({ curX, curY + 1 });
		q.push({ curX, curY - 1 });


	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag = false;
	cin >> n >> m;

	isVisited_BFS = new bool* [m];
	isFixed = new bool* [m];
	graph = new int* [m];
	days = new int* [m];

	for (int i = 0; i < m; ++i)
	{
		isVisited_BFS[i] = new bool[n] {false};
		isFixed[i] = new bool[n] {false};
		graph[i] = new int[n];
		days[i] = new int[n];
	}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				q.push({ j, i });
			days[i][j] = 0;
		}

	BFS();

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cnt = max(cnt, days[i][j]);
			if (graph[i][j] == 0)
				flag = true;
		}
	}

	cout << (flag ? -1 : cnt);
}