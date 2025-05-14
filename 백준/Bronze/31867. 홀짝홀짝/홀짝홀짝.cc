#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n, odd = 0, even = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char num;
		cin >> num;


		if ((num - '0') % 2 == 0)
			even++;
		else
			odd++;
	}

	if (odd == even) cout << -1;
	else cout << (odd > even ? 1 : 0);
}