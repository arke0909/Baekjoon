#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, bit = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		if (str == "add")
		{
			int num;
			cin >> num;

			bool value = bit & (1 << num - 1);
			if (value)
				continue;

			bit |= (1 << num - 1);
		}
		else if (str == "remove")
		{
			int num;
			cin >> num;

			bool value = bit & (1 << num - 1);
			if (!value)
				continue;

			bit &= ~(1 << num - 1);
		}
		else if (str == "check")
		{
			int num;
			cin >> num;

			bool value = bit & (1 << num - 1);
			cout << value << '\n';
		}
		else if (str == "toggle")
		{
			int num;
			cin >> num;

			bool value = bit & (1 << num - 1);
			if (value)
			{
				bit ^= (1 << num - 1);
			}
			else
			{
				bit |= (1 << num - 1);
			}
		}
		else if (str == "all")
		{
			bit = 0b11111111111111111111;
		}
		else if (str == "empty")
		{
			bit = 0b0;
		}	
	}
	return 0;
}