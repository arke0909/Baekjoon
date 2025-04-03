#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

string str[8] =
{
	"FBFBFBFBFB",
	"BFBFBFBFBF",
	"FBFBFBFBFB",
	"BFBFBFBFBF",
	"FBFBFBFBFB",
	"BFBFBFBFBF",
	"FBFBFBFBFB",
	"BFBFBFBFBF"
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string f[8];
	int cnt = 0;

	for (int i = 0; i < 8; ++i)
	{
		cin >> f[i];
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (str[i][j] == f[i][j])
				++cnt;
		}
	}

	cout << cnt;

	return 0;
}