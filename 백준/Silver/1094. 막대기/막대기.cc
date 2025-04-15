#include <iostream>

using namespace std;

unsigned long long typedef ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, cnt = 0;
	cin >> x;

	for (int i = 0; i < 7; ++i)
	{
		bool value = x & 1 << i;
		if (value)
			cnt++;
	}

	cout << cnt;

	return 0;
}