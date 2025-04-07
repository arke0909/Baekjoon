#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, cnt = 0;
	map<string, int> name = map<string, int>();
	vector<string> strs;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		name[str]++;
	}
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		name[str]++;
	}

	for (const auto& item : name)
	{
		if (item.second > 1)
		{
			++cnt;
			strs.push_back(item.first);
		}
	}

	sort(strs.begin(), strs.end());

	cout << cnt << '\n';
	for (auto item : strs)
		cout << item << '\n';

	return 0;
}