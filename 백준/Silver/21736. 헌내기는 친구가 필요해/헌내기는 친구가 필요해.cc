#include <iostream>
using namespace std;

int n, m, cnt = 0;
char** map;
bool** isVisited;

void DFS(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n) return;

	if (isVisited[y][x]) return;

	isVisited[y][x] = true;

	if (map[y][x] == 'X') return;

	if (map[y][x] == 'P')
	{
		cnt++;
	}

	DFS(x - 1, y);
	DFS(x + 1, y);
	DFS(x, y - 1);
	DFS(x, y + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int startX = 0, startY = 0;

	cin >> n >> m;

	map = new char* [n];
	isVisited = new bool* [n];
	for (int i = 0; i < n; ++i)
	{
		map[i] = new char[m + 1];
		isVisited[i] = new bool[m] {false, };
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'I')
			{
				startX = j;
				startY = i;
			}
		}

		map[i][m] = '\0';
	}

	DFS(startX, startY);

	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;
}