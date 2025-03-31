#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n;
	int num = 0;

	getline(cin, n);

	for (int i = 0; i < n.size(); i++)
	{
		num = (num * 10) + n[i] - '0';
	}

	string* arr = new string[num];

	for (int i = 0; i < num; i++)
	{
		getline(cin, arr[i]);
	}

	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << ". " << arr[i] << '\n';
	}

	return 0;
}