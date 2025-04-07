#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	map<int, string> numToName = map<int, string>();
	map<string, int> nameToNum = map<string, int>();

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		string name;
		cin >> name;
		numToName[i] = name;
		nameToNum[name] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;

		if (isdigit(str[0]))
		{
			int num = stoi(str);
			cout << numToName[num] << '\n';
		}
		else
		{
			cout << nameToNum[str] << '\n';
		}
	}

	return 0;
}