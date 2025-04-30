#include <iostream>
using namespace std;

int main() 
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	cout << min(min(abs((a + b) - (c + d)), abs((a + c) - (b + d))), abs((a + d) - (b + c)));
}