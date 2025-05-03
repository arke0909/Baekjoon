#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue <pair<int, int>> q;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		pair<int, int> value;
		cin >> value.second;

		value.first = -abs(value.second);
		value.second *= -1;

		if (value.second == 0)
		{
			if (q.size() == 0)
			{
				cout << 0 << '\n';
				continue;
			}

			cout << -q.top().second << '\n';
			q.pop();
		}
		else
		{
			q.push(value);
		}
	}

	return 0;
}