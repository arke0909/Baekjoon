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

		// 원하는 값일 경우 true 반환
		if (target == arr[mid])
			return true;

		// 원하는 값이 더 크다면 검사 범위를 더 크게
		if (target > arr[mid])
			low = mid + 1;

		// 원하는 값이 더 작다면 검사 범위를 더 작게
		else if (target < arr[mid])
			high = mid - 1;
	}

	// 그래도 못찾는다면 없으니 false를 리턴
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
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}