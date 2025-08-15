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

	int chk = 0;
	for (int i = 0; i < n; ++i)
	{
		bool flag = save.size() != 0 && save[cnt - 1] > vec[i];
		if (flag || chk == vec[i]) continue;
		save.push_back(vec[i]);
		chk = vec[i];
		Back(cnt + 1);
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
		int v;
		cin >> v;
		vec.push_back(v);
	}

	sort(vec.begin(), vec.end());

	Back(0);
}