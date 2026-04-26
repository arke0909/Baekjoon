#include "iostream"
#include "vector"
#include "queue"
#include "unordered_map"
#include "algorithm"
using namespace std;

int n;
vector<vector<char>> map(10001, vector<char>(10001, ' '));

void SetTriangle(int x, int y)
{
	map[y][x] = '*';
	map[y + 1][x + 1] = '*';
	map[y + 1][x - 1] = '*';

	for (int i = x - 2; i <= x + 2; ++i) map[y + 2][i] = '*';
}

void SetTriangle(int x, int y, int len)
{
	if (len == 3)
	{
		SetTriangle(x, y);
		return;
	}
	
	int halfLen = len / 2;
		
	SetTriangle(x, y, halfLen);
	SetTriangle(x + halfLen, y + halfLen, halfLen);
	SetTriangle(x - halfLen, y + halfLen, halfLen);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	SetTriangle(n, 1, n);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 2 * n - 1; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}