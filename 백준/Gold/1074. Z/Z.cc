#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c, cnt = 0;

void DC(int x, int y, int size)
{
	if (y == r && x == c)
	{
		cout << cnt;
		return;
	}

	if (r >= y && r < y + size && c >= x && c < x + size)
	{
		DC(x, y, size / 2);
		DC(x + size / 2, y, size / 2);
		DC(x, y + size / 2, size / 2);
		DC(x + size / 2, y + size / 2, size / 2);
	}
	else
	{
		cnt += size * size;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;

	DC(0, 0, pow(2, n));
}