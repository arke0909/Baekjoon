#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, cnt1 = 0, cnt2 = 0, X[4]{ -1, 0, 1, 0 }, Y[4]{0, -1 ,0 ,1};
bool isVisited_Norma[100][100];
bool isVisited_RedGreen[100][100];
vector<string> rgb_Normal(100);
vector<string> rgb_RedGreen(100);

void DFS_Normal(int x, int y)
{
	isVisited_Norma[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + X[i];
		int ny = y + Y[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		if (!isVisited_Norma[ny][nx] && rgb_Normal[ny][nx] == rgb_Normal[y][x])
		{
			DFS_Normal(nx, ny);
		}
	}

	rgb_Normal[y][x] = 'c';
}

void DFS_RedGreen(int x, int y)
{
	isVisited_RedGreen[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + X[i];
		int ny = y + Y[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		bool flag = rgb_RedGreen[ny][nx] == rgb_RedGreen[y][x] ||
			((rgb_RedGreen[y][x] == 'R' && rgb_RedGreen[ny][nx] == 'G') ||
				(rgb_RedGreen[y][x] == 'G' && rgb_RedGreen[ny][nx] == 'R'));

		if (!isVisited_RedGreen[ny][nx] && flag)
		{
			DFS_RedGreen(nx, ny);
		}
	}

	rgb_RedGreen[y][x] = 'c';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> rgb_Normal[i];
	}

	rgb_RedGreen = rgb_Normal;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (rgb_Normal[i][j] != 'c')
			{
				DFS_Normal(j, i);
				cnt1++;
			}

			if (rgb_RedGreen[i][j] != 'c')
			{
				DFS_RedGreen(j, i);
				cnt2++;
			}
		}
	}

	cout << cnt1 << ' ' << cnt2;
}