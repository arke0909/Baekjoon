#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		priority_queue<ll> maxQ;
		priority_queue<ll> minQ;
		map<ll, ll> flagTable;

		int k;
		cin >> k;

		for (int i = 0; i < k; ++i)
		{
			char command;
			ll v;
			cin >> command >> v;

			if (command == 'I')
			{
				maxQ.push(v);
				minQ.push(-v);
				flagTable[v]++;
			}
			else if (command == 'D')
			{
				if (v == 1)
				{
					if (!maxQ.empty())
					{
						flagTable[maxQ.top()]--;
						maxQ.pop();
					}
				}
				else
				{
					if (!minQ.empty())
					{
						flagTable[-minQ.top()]--;
						minQ.pop();
					}
				}

				while (!maxQ.empty() && flagTable[maxQ.top()] == 0)
				{
					maxQ.pop();
				}
				while (!minQ.empty() && flagTable[-minQ.top()] == 0)
				{
					minQ.pop();
				}
			}
		}

		if (maxQ.empty() && minQ.empty())
			cout << "EMPTY\n";
		else
			cout << maxQ.top() << ' ' << -minQ.top() << '\n';
	}
}