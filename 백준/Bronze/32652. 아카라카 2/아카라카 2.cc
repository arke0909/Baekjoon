#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << "AKARAKA";
	for (int i = 1; i < n; ++i)
		cout << "RAKA";

	return 0;
}