#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 0, idx = 0;
	int arr[6]{ 500, 100, 50, 10, 5, 1 };

	cin >> n;

	int m = 1000 - n;

	while (true)
	{
		if (m - arr[idx] >= 0)
		{
			m -= arr[idx];

			++cnt;
		}
		else
			idx++;

		if (m == 0)
			break;
	}

	cout << cnt;

	return 0;
}