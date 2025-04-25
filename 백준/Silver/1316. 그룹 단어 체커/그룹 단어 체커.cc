#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		bool conform[26]{false};
		string str;
		cin >> str;

		int strSize = str.size();
		conform[str[0] - 'a'] = true;

		if (strSize == 1)
			cnt++;
		else
		for (int j = 1; j < str.size(); ++j)
		{
			if ((str[j] - 'a' != str[j - 1] - 'a') && conform[str[j] - 'a'] == true)
				break;
			
			if (conform[str[j] - 'a'] == false)
				conform[str[j] - 'a'] = true;

			if (j == str.size() - 1)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}