#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a, char b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	vector<int> v;

	for (int i = 0; i < str.size(); ++i)
		v.push_back(str[i]);
	
	sort(v.begin(), v.end(), cmp);

	for (auto item : v)
		cout << (char)item;

	return 0;
}