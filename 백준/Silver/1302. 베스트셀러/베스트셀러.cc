#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> map;
	string answer;
	int n, check = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		map[str]++;
	}

	for (auto book : map)
	{
		if (check < book.second)
		{
			check = book.second;
			answer = book.first;
		}
	}

	cout << answer;
}