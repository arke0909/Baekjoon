#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, total;

	cin >> a >> b >> c;

	total = a + b + c;

	if (a == 60 && a == b && b == c)
		cout << "Equilateral";
	else if (total == 180 && (a == b || b == c || c == a))
		cout << "Isosceles";
	else if (total == 180)
		cout << "Scalene";
	else if(total != 180)
		cout << "Error";


	return 0;
}