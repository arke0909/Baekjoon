#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int arr[101];

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;

		cin >> a >> b;

		if (a == b) continue;

		if (abs(a - b) == 1)
		{
			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
		else
		{
			while (a < b)
			{
				int temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;

				++a;
				--b;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << arr[i] << ' ';
	return 0;
}