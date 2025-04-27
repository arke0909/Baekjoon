#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int* arr = new int[n + 1], * s = new int[n + 1] {0};

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		s[i] = s[i - 1] + arr[i];
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << s[b] - s[a - 1] << '\n';
	}

	return 0;
}