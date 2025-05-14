#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, m, i;
	queue<int> q;
	cin >> n >> t;

	for (i = 0; i < 2 * n; ++i)
	{
		int v;
		cin >> v;
		q.push(v);
	}

	for (i = 0; i < t; ++i)
	{
		int v, idx = 1;
		cin >> v;

		while (true)
		{
			if (idx == v)
			{
				cout << q.front() << ' ';
				break;
			}

			q.push(q.front());
			q.pop();
			idx++;
		}
	}
}