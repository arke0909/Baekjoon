#include <iostream>
using namespace std;

int main() 
{
	char a, b, c, d;
	cin >> a >> b >> c >> d;

	cout << (a == 'I' ? 'E' : 'I') << (b == 'S' ? 'N' : 'S') << (c == 'T' ? 'F' : 'T') << (d == 'J' ? 'P' : 'J');
}