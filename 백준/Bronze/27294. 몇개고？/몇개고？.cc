#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int hour, sake, grain;
	bool flag = false;
	cin >> hour >> sake;

	if ((hour <= 11 || 16 < hour) || sake != 0)
		flag = true;

	grain = flag ? 280 : 320;

	cout << grain;
}