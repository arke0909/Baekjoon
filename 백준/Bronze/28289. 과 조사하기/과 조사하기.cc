#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, s = 0, im = 0, a = 0, any = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int g, c, n;
		cin >> g >> c >> n;

		if (g == 1)
		{
			any++;
			continue;
		}
		else if (c == 1 || c == 2)
		{
			s++;
		}
		else if (c == 3)
		{
			im++;
		}
		else if (c == 4)
		{
			a++;
		}
	}
	cout << s << '\n';
	cout << im << '\n';
	cout << a << '\n';
	cout << any << '\n';
}