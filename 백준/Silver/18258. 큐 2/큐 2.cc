#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, v, i;
	string command;
	queue<int> q;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> v;
			q.push(v);
		}
		else if (command == "pop")
		{
			if (q.size() != 0)
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << "-1" << '\n';
		}
		else if (command == "size")
		{
			cout << q.size() << '\n';
		}
		else if (command == "empty")
		{
			cout << (int)(q.size() == 0) << '\n';
		}
		else if (command == "front")
		{
			if (q.size() != 0)
				cout << q.front() << '\n';
			else
				cout << "-1" << '\n';
		}
		else if (command == "back")
		{
			if (q.size() != 0)
				cout << q.back() << '\n';
			else
				cout << "-1" << '\n';
		}
	}
}