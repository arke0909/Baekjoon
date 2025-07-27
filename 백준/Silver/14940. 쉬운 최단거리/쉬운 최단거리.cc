#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, X[4]{ -1, 0, 1, 0 }, Y[4]{ 0, -1 ,0 ,1 }, map[1000][1000], length[1000][1000];
bool isVisited[1000][1000];

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x ,y });
	isVisited[y][x] = true;
	length[y][x] = 0;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = curX + X[i];
			int ny = curY + Y[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

			if (!isVisited[ny][nx] && map[ny][nx] != 0)
			{
				isVisited[ny][nx] = true;
				length[ny][nx] = length[curY][curX] + 1;
				q.push({ nx, ny });
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
			length[i][j] = -1;
			if (map[i][j] == 0)
				length[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 2)
				BFS(j, i);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << length[i][j] << ' ';
		}
		cout << '\n';
	}

}