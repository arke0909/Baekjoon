#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	if (m == 1 || m == 2) std::cout << "NEWBIE!";
	else if(m <= n) std::cout << "OLDBIE!";
	else std::cout << "TLE!";
}
