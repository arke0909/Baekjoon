#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;

	cin >> a >> b;

	cout << a + b << '\n' << a - b << '\n' << a * b << '\n' << a / b << '\n' << a % b << '\n';
}