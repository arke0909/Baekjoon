#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[26], n;
	bool isConfirm = false;
	fill_n(arr, 26, 0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		arr[str[0] - 'a']++;
	}

	for (int i = 0; i < 26; ++i)
		if (arr[i] >= 5)
			isConfirm = true;

	if (isConfirm)
	{
		for (int i = 0; i < 26; ++i)
			if (arr[i] >= 5)
				cout << (char)(i + 'a');
	}
	else
		cout << "PREDAJA";

		return 0;
}