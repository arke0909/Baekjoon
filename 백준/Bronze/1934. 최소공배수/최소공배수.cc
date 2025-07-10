#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b, r, v;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		r = 1;
		cin >> a >> b;
		v = a * b;

		while (r != 0)
		{
			if (a < b)
				swap(a, b);

			r = a % b;

			if (r == 0)
				break;

			a = b;
			b = r;
		}

		cout << v / b << '\n';
	}
}
