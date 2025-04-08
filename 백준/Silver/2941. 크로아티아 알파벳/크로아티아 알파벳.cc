#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strs[8]{ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;
	int n = 0;
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		bool can = true;

		for (auto c : strs)
		{
			for (int j = 0; j < c.size(); ++j)
			{
				can = str[j] == c[j];
				if (!can)
					break;
			}

			if (can)
			{
				i = -1;
				str.erase(str.find(c), c.size());
				break;
			}
		}

		if (!can)
		{
			i = -1;
			str.erase(0, 1);
		}
		n++;
	}

	cout << n;

	return 0;
}