#include<iostream>
using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	int* arr = new int[n + 1];

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';

	/*int n, min = 2147483647;

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int target = arr[i];

		for (int j = 0; j < n; j++)
		{
			int temp = arr[j];

			if (temp == target) continue;

			if (target < temp)
			{
				int dummy = target;
				target = temp;
				temp = dummy;
			}

			int diff = target - temp;

			if (diff < min)
				min = diff;
		}
	}

	cout << min;*/
}