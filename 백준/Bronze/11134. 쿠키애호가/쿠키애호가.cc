#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int m, l, cnt;
		cin >> m >> l;

		cnt = m / l;
		if (m % l >= 1)
			cnt++;

		cout << cnt << '\n';
	}
}


