#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 0;
	vector<int> a, b;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		a.push_back(v);
	}
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		b.push_back(v);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; ++i)
	{
		cnt += a[i] * b[n - i - 1];
	}

	cout << cnt;
}
