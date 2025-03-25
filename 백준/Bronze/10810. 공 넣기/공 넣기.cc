#include <iostream>
using namespace std;

int main()
{
	int n,m;

	cin >> n >> m;

	int* arr = new int[n + 1] {0};

	for (int a = 0; a < m; a++)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int b = i; b <= j; b++)
			arr[b] = k;
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
}

