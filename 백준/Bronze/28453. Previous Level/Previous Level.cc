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
		int v;
		cin >> v;

		if (v >= 300)
			cout << 1 << ' ';
		else if (v < 300 && 275 <= v)
			cout << 2 << ' ';
		else if (v < 275 && 250 <= v)
			cout << 3 << ' ';
		else if (250 > v)
			cout << 4 << ' ';
	}
}