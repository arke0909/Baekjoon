#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	if (m * 100 < n)
		cout << "No";
	else cout << "Yes";
}