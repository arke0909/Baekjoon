#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, m, M, T, R, base, result = 0, cnt = 0;
	cin >> N >> m >> M >> T >> R;
	base = m;

	if ((M - m) < T)
		cout << -1;
	else
	{
		while (cnt != N)
		{
			if (base + T <= M)
			{
				cnt++;
				base += T;
			}
			else
			{
				base -= R;
				if (base <= m)
					base = m;
			}

			result++;
		}

		cout << result;
	}
}