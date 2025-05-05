#include <iostream>
#include <string>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n, checkW[8] = { -1, -1, 0, 1 ,1, 1, 0,-1 }, checkH[8] = {0, 1, 1, 1, 0, -1, -1, -1 };
	cin >> n;

	string* strs = new string [n];
	for (int i = 0; i < n; ++i)
		cin >> strs[i];

	for (int i = 0; i < n;++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int cnt = 0;
			char c = strs[i][j];
			if (c != '.')
			{
				cout << '*';
				continue;
			}
			for (int l = 0; l < 8; ++l)
			{
				int x = j + checkW[l], y = i + checkH[l];
				if (x < 0 || x >= n || y < 0 || y >= n) continue;

				c = strs[y][x];
				if (c == '.')
					continue;
				else
					cnt += c - '0';
			}

			if (cnt >= 10)
				cout << 'M';
			else
				cout << cnt;
		}
		cout << '\n';
	}
}