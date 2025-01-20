#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,a,b;

	cin >> n >> a >> b;

	if (a < b && n <= b)
		cout << "Bus";
	else if (a == b && n <= b)
		cout << "Anything";
	else
		cout << "Subway";
}