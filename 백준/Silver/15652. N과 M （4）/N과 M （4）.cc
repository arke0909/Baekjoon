#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;
vector<int> save;

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
		if (save.size() != 0)
			if (save[cnt - 1] > vec[i])
				continue;
		save.push_back(vec[i]);
		Back(cnt + 1);
		if (save.size() != 0)
			save.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		vec.push_back(i + 1);
	}

	sort(vec.begin(), vec.end());

	Back(0);
}