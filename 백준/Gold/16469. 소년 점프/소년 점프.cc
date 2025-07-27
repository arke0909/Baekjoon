#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int r, c, totalTime = 100000;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int** cntTable1;
int** cntTable2;
int** cntTable3;
bool** isVisited1;
bool** isVisited2;
bool** isVisited3;
char** graph;

void BFS(int x, int y, int** cntTable, bool** isVisited)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	isVisited[y][x] = true;
	cntTable[y][x] = 0;

	while (!q.empty())
	{
		int currentX = q.front().first;
		int currnetY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextX = currentX + dx[i];
			int nextY = currnetY + dy[i];

			if (nextX >= 0 && nextX < c && nextY >= 0 && nextY < r)
			{
				if (!isVisited[nextY][nextX] && graph[nextY][nextX] == '0')
				{
					q.push({ nextX, nextY });
					isVisited[nextY][nextX] = true;
					cntTable[nextY][nextX] = cntTable[currnetY][currentX] + 1;
				}
			}
		}
	}
}

bool CheckZero(int x, int y, bool** isVisited)
{
	return !isVisited[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag = false;
	map<int, int> cntMap;
	cin >> r >> c;

	cntTable1 = new int* [r];
	cntTable2 = new int* [r];
	cntTable3 = new int* [r];
	graph = new char* [r];
	isVisited1 = new bool* [r];
	isVisited2 = new bool* [r];
	isVisited3 = new bool* [r];

	for (int i = 0; i < r; ++i)
	{
		cntTable1[i] = new int [c] {0};
		cntTable2[i] = new int [c] {0};
		cntTable3[i] = new int [c] {0};
		graph[i] = new char[c];
		isVisited1[i] = new bool[c] {false};
		isVisited2[i] = new bool[c] {false};
		isVisited3[i] = new bool[c] {false};
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> graph[i][j];
		}
	}

	int x, y;
	cin >> y >> x;
	BFS(x - 1, y - 1, cntTable1, isVisited1);
	cin >> y >> x;
	BFS(x - 1, y - 1, cntTable2, isVisited2);
	cin >> y >> x;
	BFS(x - 1, y - 1, cntTable3, isVisited3);

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (CheckZero(j, i, isVisited1) || CheckZero(j, i, isVisited2) || CheckZero(j, i, isVisited3)) continue;
			int temp = max(cntTable1[i][j], max(cntTable2[i][j], cntTable3[i][j]));

			flag = true;

			if (totalTime > temp)
			{
				totalTime = temp;
				cntMap[temp] = 1;
			}
			else if (totalTime == temp)
			{
				cntMap[temp]++;
			}
		}
	}

	if (flag)
		cout << totalTime << '\n' << cntMap[totalTime];
	else
		cout << -1;
}


