#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, pair<int, int>> map;

	while (true)
	{
		string name;

		cin >> name;

		cin >> map[name].first;
		cin >> map[name].second;

		if (name == "#")
			break;

		bool conform = map[name].first > 17 || map[name].second >= 80;
		string str = conform ? "Senior" : "Junior";
		cout << name << ' ' << str << '\n';
	}

	return 0;
}