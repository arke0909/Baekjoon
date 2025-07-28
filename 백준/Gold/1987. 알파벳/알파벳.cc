#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, arr[26]{ 0 },maxN = 0, cnt = 1, X[4]{ -1, 0, 1, 0 }, Y[4]{ 0, -1, 0, 1 };
string map[20];

void Back(int x, int y)
{
	maxN = max(maxN, cnt);
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + X[i];
		int ny = y + Y[i];

		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
		if (arr[map[ny][nx] - 'A'] == 1) continue;

		cnt++;
		arr[map[ny][nx] - 'A'] = 1;
		Back(nx, ny);
		arr[map[ny][nx] - 'A'] = 0;
		cnt--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		cin >> map[i];
	}

	arr[map[0][0] - 'A'] = 1;
	Back(0, 0);

	cout << maxN;
}


