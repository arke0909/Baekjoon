#include <iostream>
#include <string>
using namespace std;


int main()
{
		int n, k,j = 0,m = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) {
			j++;
			if (j == k)
			{
				m = i;
				break;
			}
		}
	}

				cout << m;

	return 0;
}