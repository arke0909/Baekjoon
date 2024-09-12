#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, num[3], a,b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[0] >> num[1] >> num[2];
		a = num[1] > num[2] ? num[2] : num[1];
		b = num[0] > a ? a : num[0];
		cout << b << endl;
	}
	return 0;
}