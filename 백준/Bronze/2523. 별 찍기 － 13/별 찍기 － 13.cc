#include <iostream>

using namespace std;

void Star(int n, int target)
{

	for (int i = 0; i < n; ++i)
		cout << '*';

	cout << '\n';
	
	if (n == target) return;
	
	Star(n + 1, target);

	for (int i = 0; i < n; ++i)
		cout << '*';

	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	Star(1, n);

	return 0;
}