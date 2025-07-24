#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int n, height, cnt = 0;
		char** message;
		cin >> n;
		if (n == 0) break;

		string str;
		cin >> str;

		height = str.size() / n;
		message = new char* [height];
		for (int i = 0; i < height; ++i)
			message[i] = new char[n];

		for (int i = 0; i < height; ++i)
		{
			if (i % 2 == 0)
				for (int j = 0; j < n; ++j)
				{
					message[i][j] = str[cnt++];
				}
			else
				for (int j = n - 1; j > -1; --j)
				{
					message[i][j] = str[cnt++];
				}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				cout << message[j][i];
			}
		}
		cout << '\n';
	}
}