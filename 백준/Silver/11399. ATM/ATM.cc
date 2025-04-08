#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, idx = 0, total = 0;

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	while (true)
	{
		for (int i = 0; i <= idx; ++i)
			total += arr[i];

		idx++;

		if (idx == n)
			break;
	}

	cout << total;

	return 0;
}