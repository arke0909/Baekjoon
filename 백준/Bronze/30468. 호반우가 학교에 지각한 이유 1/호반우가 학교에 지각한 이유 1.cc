#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	int a, b, c, d, e, f = 0;
	cin >> a >> b >> c >> d >> e;

	while (true)
	{
		if ((a + b + c + d + f) / 4 >= e)
			break;

		f++;
	}

	cout << f;
}


