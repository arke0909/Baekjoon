#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total = 0;

	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;

		n = n < 40 ? 40 : n;

		total += n;
	}

	cout << total / 5;


	return 0;
}