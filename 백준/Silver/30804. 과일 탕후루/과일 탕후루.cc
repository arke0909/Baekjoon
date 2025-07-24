#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[10]{0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	int n, kind = 0, result = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;

		if (arr[v]++ == 0)
		{
			kind++;
		}

		q.push(v);

		while (kind > 2)
		{
			int v = q.front();

			q.pop();

			if (--arr[v] == 0)
			{
				kind--;
			}
		}

		result = max((int)q.size(), result);
	}

	cout << result;
}