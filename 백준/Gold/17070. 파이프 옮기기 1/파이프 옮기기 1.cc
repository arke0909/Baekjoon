#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

int n, cnt = 0;
vector<vector<int>> map;

bool CanMoveHorizontal(int x, int y)
{
	return x <= n && map[y][x] != 1;
}
bool CanMoveVertical(int x, int y)
{
	return y <= n && map[y][x] != 1;
}
bool CanMoveDiagonal(int x, int y)
{
	return CanMoveHorizontal(x, y - 1) && CanMoveVertical(x - 1, y) && map[y][x] != 1;
}

void BackTracking(int x1, int y1, int x2, int y2)
{
	if (x2 == n && y2 == n)
	{
		cnt++;
		return;
	}

	// 현재 파이프 형태 구하기

	int xd = x2 - x1;
	int yd = y2 - y1;

	if (xd == 1 && yd == 1) // 대각선
	{
		if (CanMoveHorizontal(x2 + 1, y2))
			BackTracking(x1 + 1, y1 + 1, x2 + 1, y2);
		if (CanMoveVertical(x2, y2 + 1))
			BackTracking(x1 + 1, y1 + 1, x2, y2 + 1);
		if (CanMoveDiagonal(x2 + 1, y2 + 1))
			BackTracking(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
	}
	else if (xd == 1 && yd == 0) // 가로
	{
		if (CanMoveHorizontal(x2 + 1, y2))
			BackTracking(x1 + 1, y1, x2 + 1, y2);
		if (CanMoveDiagonal(x2 + 1, y2 + 1))
			BackTracking(x1 + 1, y1, x2 + 1, y2 + 1);
	}
	else if (xd == 0 && yd == 1) // 세로
	{
		if (CanMoveVertical(x2, y2 + 1))
			BackTracking(x1, y1 + 1, x2, y2 + 1);
		if (CanMoveDiagonal(x2 + 1, y2 + 1))
			BackTracking(x1, y1 + 1, x2 + 1, y2 + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	map = vector(n + 1, vector(n + 1, 0));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}

	BackTracking(1, 1, 2, 1);

	cout << cnt;
}