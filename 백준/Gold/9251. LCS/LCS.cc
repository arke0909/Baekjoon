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

	string str1, str2;
	int** lcs, answer = 0;

	cin >> str1 >> str2;

	lcs = new int* [str1.size() + 1];
	
	for (int i = 0; i < str1.size() + 1; ++i)
	{
		lcs[i] = new int[str2.size() + 1];
	}

	for (int i = 0; i < str1.size() + 1; ++i)
		lcs[i][0] = 0;
	for (int i = 0; i < str2.size() + 1; ++i)
		lcs[0][i] = 0;

	for (int i = 1; i < str1.size() + 1; ++i)
	{
		for (int j = 1; j < str2.size() + 1; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}

			answer = max(answer, lcs[i][j]);
		}
	}

	cout << answer;
}
