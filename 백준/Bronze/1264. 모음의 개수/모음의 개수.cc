#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string aeiou = "aeiouAEIOU";

	while (true)
	{
		int cnt = 0;
		string str;
		getline(cin,str);

		if (str == "#")
			break;

		for (int i = 0; i < str.size(); ++i)
		{
			for (auto c : aeiou)
			{
				if (c == str[i])
					cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}