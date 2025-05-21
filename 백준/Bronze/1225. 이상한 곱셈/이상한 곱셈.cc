#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n, m;
	unsigned long long N = 0, M = 0;
	cin >> n >> m;

	for (int i = 0; i < m.size(); ++i)
		M += m[i] - '0';

	for (int i = 0; i < n.size(); ++i)
		N += n[i] - '0';

	cout << N * M;
}