#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int> q;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;

		value *= -1;

		if (value == 0)
		{
			if (q.size() == 0)
			{
				cout << 0 << '\n';
				continue;
			}

			cout << -q.top() << '\n';
			q.pop();
		}
		else
		{
			q.push(value);
		}
	}

	return 0;
}