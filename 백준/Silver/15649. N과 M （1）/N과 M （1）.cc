#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;
vector<int> save;
bool* isVisit;

void Back(int cnt)
{
	if (cnt == m)
	{
		for (auto item : save)
			cout << item << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (isVisit[i]) continue;
		isVisit[i] = true;
		save.push_back(vec[i]);
		Back(cnt + 1);
		isVisit[i] = false;
		save.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	isVisit = new bool[n];

	for (int i = 0; i < n; ++i)
	{
		vec.push_back(i + 1);
	}

	sort(vec.begin(), vec.end());

	Back(0);
}