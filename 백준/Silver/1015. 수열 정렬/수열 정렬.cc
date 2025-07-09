#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> vec, cop;
	map<int, int> map;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}
	cop = vec;
	sort(cop.begin(), cop.end());
	for (auto item : vec)
	{
		cout << (lower_bound(cop.begin(), cop.end(), item) - cop.begin()) + map[item] << ' ';
		map[item]++;
	}
}
