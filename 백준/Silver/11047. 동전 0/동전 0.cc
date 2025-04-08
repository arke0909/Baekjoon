#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, idx = 0, cnt = 0;

	cin >> n >> m;

	int* arr = new int[n];

	for (int i = n - 1; i >= 0; --i)
		cin >> arr[i];

	while (true)
	{
		if (m - arr[idx] >= 0)
		{
			m -= arr[idx];
			cnt++;
		}
		else
			idx++;

		if (m == 0)
			break;
	}

	cout << cnt;

	return 0;
}