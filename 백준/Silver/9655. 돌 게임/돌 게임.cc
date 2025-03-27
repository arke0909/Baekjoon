#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n, m = 1;
string sk = "SK";
string cy = "CY";
bool isSK = true;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (true)
	{
		if (m + 3 <= n)
		{
			m += 3;
			isSK = !isSK;
			continue;
		}

		if (m + 1 <= n)
		{
			m += 1;
			isSK = !isSK;
			continue;
		}

		break;
	}

	cout << (isSK ? sk : cy);

	return 0;
}