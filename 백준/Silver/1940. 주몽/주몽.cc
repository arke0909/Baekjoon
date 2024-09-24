#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, total,cnt = 0;

	cin >> n >> total;

	int* N = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
	}

	sort(N, N + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((N[i] + N[j]) == total && i != j) cnt++;
		}
	}

	cout << cnt / 2;

	return 0;
}