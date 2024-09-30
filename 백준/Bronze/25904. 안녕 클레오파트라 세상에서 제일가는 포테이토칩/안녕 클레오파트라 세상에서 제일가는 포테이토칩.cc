#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;int main()
{	int n, x, idx = 0;

	cin >> n >> x;

	int* limit = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> limit[i];
	}

	while (true)
	{
		if (x++ > limit[idx]) break;
		idx = (idx + 1) % n;
	}

	cout << idx + 1;

		return 0;
	}