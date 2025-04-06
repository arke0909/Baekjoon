#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, total = 1023, result;
	
	cin >> a >> b;

	result = ~(0 | ((a & b) | ~(a | b)));

	cout << result;

	return 0;
}