#include <iostream>
using namespace std;

int n, s, cnt = 0, arr[20];

void Back(int idx = 0, int total = 0)
{
	if (idx == n)
	{
		if (total == s) cnt++;
		return;
	}

	Back(idx + 1, total + arr[idx]);

	Back(idx + 1, total);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	Back();

	if (s == 0) cnt--;

	cout << cnt;

	return 0;
}

