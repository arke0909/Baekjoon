#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n,k,res;
	queue<int> josephus;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		josephus.push(i);

	cout << '<';

	while (josephus.size() != 0)
	{
		for (int i = 1; i <= k; i++)
		{
			if(i != k)
			josephus.push(josephus.front());
			res = josephus.front();
			josephus.pop();
		}

		cout << res;
		if (josephus.empty())
			break;
		else cout << ", ";
	}
	cout << '>';

	return 0;
}