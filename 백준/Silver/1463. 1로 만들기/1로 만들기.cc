#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	int* arr = new int[n + 1] {0};

	// 1은 연산 횟수가 0이니 2부터 시작
	for (int i = 2; i <= n; i++)
	{
		// X에서 1을 뺀 연산
		arr[i] = arr[i - 1] + 1;

		// X가 3으로 나누어 떨어질 때 1을 뺀 연산과 3으로 나눈 연산 중 더 작은 값으로 선택
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		// X가 2으로 나누어 떨어질 때 1을 뺀 연산과 2로 나눈 연산 중 더 작은 값으로 선택
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
	}

	cout << arr[n];


	return 0;
}