#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;


	map<string, string> stringMap = map<string, string>();

	for (int i = 0; i < n; ++i)
	{
		string site, password;
		cin >> site >> password;
		stringMap[site] = password;
	}

	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		cout << stringMap[str] << '\n';
	}

	return 0;
}