#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;

	int*** lcs = new int** [str1.size() + 1];
	int answer = 0;

	for (int i = 0; i < str1.size() + 1; ++i)
	{
		lcs[i] = new int* [str2.size() + 1];

		for (int j = 0; j < str2.size() + 1; ++j)
		{
			lcs[i][j] = new int[str3.size() + 1];
		}
	}

	for (int i = 0; i < str1.size() + 1; ++i)
		for (int j = 0; j < str2.size() + 1; ++j)
			lcs[i][j][0] = 0;

	for (int i = 0; i < str1.size() + 1; ++i)
		for (int j = 0; j < str3.size() + 1; ++j)
			lcs[i][0][j] = 0;

	for (int i = 0; i < str2.size() + 1; ++i)
		for (int j = 0; j < str3.size() + 1; ++j)
			lcs[0][i][j] = 0;

	for (int i = 1; i < str1.size() + 1; ++i)
	{
		for (int j = 1; j < str2.size() + 1; ++j)
		{
			for (int l = 1; l < str3.size() + 1; ++l)
			{
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[l - 1])
				{
					lcs[i][j][l] = lcs[i - 1][j - 1][l - 1] + 1;
				}
				else
				{
					lcs[i][j][l] = max({ lcs[i - 1][j][l],lcs[i][j][l - 1],lcs[i][j - 1][l],lcs[i][j - 1][l - 1], lcs[i - 1][j - 1][l], lcs[i - 1][j][l - 1]});
				}

				answer = max(answer, lcs[i][j][l]);
			}
		}
	}

	cout << answer;
}
