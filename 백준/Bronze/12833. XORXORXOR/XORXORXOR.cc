#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b, n;

	cin >> a >> b >> n;

	if (n % 2 == 0)
		cout << a;
	else
		cout << (a ^ b);


}