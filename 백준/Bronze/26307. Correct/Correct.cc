#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int hh, mm;
	cin >> hh >> mm;

	cout << (hh - 9) * 60 + mm;
}