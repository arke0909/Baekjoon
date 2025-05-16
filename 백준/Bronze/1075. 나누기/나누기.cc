#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, f;
	string strN;
	cin >> strN >> f;

	if (strN.size() == 1)
		strN = '0' + strN;

	strN[strN.size() - 1] = '0';
	strN[strN.size() - 2] = '0';

	n = stoi(strN);

	while (true)
	{
		if (n % f == 0)
		{
			strN = to_string(n);
			break;
		}

		n++;
	}

	strN = strN.substr(strN.size() - 2, 2);
	cout << strN;
}