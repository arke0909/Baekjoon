#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 1;
	vector<pair<int, int>> vec;
	pair<int, int> curInfo;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		pair<int, int> info;
		cin >> info.first >> info.second;
		vec.push_back(info);
	}

	sort(vec.begin(), vec.end(), cmp);
	
	curInfo = vec[0];
	for (int i = 1; i < n; ++i)
	{
		if (curInfo.second <= vec[i].first)
		{
			cnt++;
			curInfo = vec[i];
		}
	}

	cout << cnt;
}