#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;
vector<int> save;
bool* isVisited;

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
		if (isVisited[i] || chk == vec[i]) continue;
		isVisited[i] = true;
		save.push_back(vec[i]);
		chk = vec[i];
		Back(cnt + 1);
		save.pop_back();
		isVisited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	isVisited = new bool[n] {false};

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}

	sort(vec.begin(), vec.end());

	Back(0);
}