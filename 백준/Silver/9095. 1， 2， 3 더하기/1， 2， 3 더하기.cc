#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;

	int arr[10] = {0};

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;

	for (int i = 3; i < 10; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << arr[n - 1] << '\n';
	}
}