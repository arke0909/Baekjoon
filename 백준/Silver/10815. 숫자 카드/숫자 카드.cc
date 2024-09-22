#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool BinarySearch(int* arr, int len, int target)
{
	int low = 0, high = len - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (target == arr[mid])
			return true;

		if (target > arr[mid])
			low = mid + 1;

		else if (target < arr[mid])
			high = mid - 1;
	}
	return false;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,num;

	cin >> n;
	int *N = new int[n];

	for (int i = 0; i < n; i++)
		cin >> N[i];

	sort(N, N + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if (BinarySearch(N, n, num))
			cout << "1 ";
		else
			cout << "0 ";
	}

	return 0;
}