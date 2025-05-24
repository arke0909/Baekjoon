#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n, result;
	cin >> n;

	for (int i = 0; i < n.size(); ++i)
	{
		bitset<3> bin(n[i] - '0');
		string str = bin.to_string();

		result += str;
	}

	while (result[0] == '0' && result.size() != 1)
		result.erase(0, 1);

	cout << result;
}