#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;

	cin >> a >> b;

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	long long result = ((long long)(a + b) * (long long)(b - a + 1)) / 2;

	cout << result;

	return 0;
}