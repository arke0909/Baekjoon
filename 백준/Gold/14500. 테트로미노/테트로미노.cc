#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int n, m, graph[501][501], cnt = 0, X[4]{ 1,-1,0,0 }, Y[4]{ 0,0,-1,1 };
bool isVisited[501][501];

void Back(int x, int y, int depth, int total)
{
	total += graph[y][x];

	if (depth == 4)
	{
		cnt = max(cnt, total);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + X[i];
		int ny = y + Y[i];

		if (ny < 1 || ny > n || nx < 1 || nx > m) continue;

		if (!isVisited[ny][nx])
		{
			isVisited[ny][nx] = true;
			Back(nx, ny, depth + 1, total);
			isVisited[ny][nx] = false;
		}
	}
}

void TBlock(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int total = graph[y][x];
		bool isValid = true;

		for (int j = 0; j < 4; ++j)
		{
			if (i == j) continue;

			int nx = x + X[j];
			int ny = y + Y[j];

			if (ny < 1 || ny > n || nx < 1 || nx > m) {
				isValid = false;
				break;
			}

			total += graph[ny][nx];
		}

		if (isValid)
			cnt = max(cnt, total);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			isVisited[i][j] = true;
			Back(j, i, 1, 0);
			isVisited[i][j] = false;
			TBlock(j, i);
		}
	}

	cout << cnt;

	return 0;
}
