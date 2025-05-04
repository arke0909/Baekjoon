#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long maxN = 2, minN = 2147483647;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		maxN = max((int)maxN, v);
		minN = min((int)minN, v);
	}	

	cout << maxN * minN;

	return 0;
}