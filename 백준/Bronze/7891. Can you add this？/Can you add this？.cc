#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long a, b, c;
		cin >> a >> b;
		c = a + b;
		cout << c << '\n';
	}
}