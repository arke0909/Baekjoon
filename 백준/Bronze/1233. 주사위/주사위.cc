#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n, m, l, minN, maxCnt = 0, result = 80;
	cin >> n >> m >> l;

	for (int i = 3; i <= n + m + l; ++i)
	{
		int cnt = 0;

		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				for (int b = 1; b <= l; ++b)
				{
					if (i == j + k + b)
						cnt++;
				}
			}
		}

		if (cnt > maxCnt)
		{
			maxCnt = cnt;
			result = i;
		}
		else if (cnt == maxCnt)
			result = min(i, result);
	}

	cout << result;
}


