#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n, m, arr[8]{0};
bool isVisited[8]{ false };
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
		if (isVisited[i]) continue;

		if (cnt != 0)
			if (save[cnt - 1] > arr[i])
				continue;

		isVisited[i] = true;

		save.push_back(arr[i]);
		Back(cnt + 1);
		save.pop_back();

		if(cnt != 0)
			isVisited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		arr[i] = i + 1;
	}

	Back(0);
}


