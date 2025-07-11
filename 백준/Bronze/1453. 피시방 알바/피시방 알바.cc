#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 0, arr[101]{0};
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		if (arr[v] != 0)
		{
			cnt++;
			continue;
		}
		arr[v]++;
	}

	cout << cnt;
}
