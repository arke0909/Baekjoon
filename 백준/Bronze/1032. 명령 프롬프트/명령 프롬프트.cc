#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> strs;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		strs.push_back(str);
	}

	for (int i = 0; i < strs[0].size(); ++i)
	{
		bool conform = true;
		int a = 0;
		for (int j = 0; j < n - 1; ++j)
		{
			if (strs[j][i] != strs[j + 1][i])
			{
				conform = false;
				continue;
			}
		}

		if (conform)
			cout << strs[0][i];
		else
			cout << '?';
	}

	return 0;
}