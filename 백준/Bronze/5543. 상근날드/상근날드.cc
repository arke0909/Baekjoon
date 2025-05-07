#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	cout << (min(a, min(b, c)) + min(d, e)) - 50;
}