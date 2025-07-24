#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, minN = 100000;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int** cntTable;
bool** isVisited;
char** graph;

int BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	isVisited[y][x] = true;
	cntTable[y][x] = 1;

	while (!q.empty())
	{
		int currentX = q.front().first;
		int currnetY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextX = currentX + dx[i];
			int nextY = currnetY + dy[i];

			if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			{
				if (!isVisited[nextY][nextX] && graph[nextY][nextX] == '1')
				{
					q.push({ nextX, nextY });
					isVisited[nextY][nextX] = true;
					cntTable[nextY][nextX] = cntTable[currnetY][currentX] + 1;
				}
			}
		}
	}

	return cntTable[n - 1][m - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	cntTable = new int* [n];
	graph = new char* [n];
	isVisited = new bool* [n];

	for (int i = 0; i < n; ++i)
	{
		cntTable[i] = new int[m] {0};
		graph[i] = new char[m];
		isVisited[i] = new bool[m] {false};
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> graph[i][j];
		}
	}

	cout <<	BFS(0, 0);
}