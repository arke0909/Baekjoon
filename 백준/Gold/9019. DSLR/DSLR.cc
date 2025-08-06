#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

char command[4]{ 'D','S','L','R' };

int Convert(int value, char cmd)
{
	if (cmd == 'D')
	{
		return (value * 2) % 10000;
	}
	else if (cmd == 'S')
	{
		return value == 0 ? 9999 : value - 1;
	}
	else if (cmd == 'L')
	{
		return (value % 1000) * 10 + value / 1000;
	}
	else if(cmd == 'R')
	{
		return (value % 10) * 1000 + value / 10;
	}
}

void BFS(int start, int target)
{
	vector<bool> visited(10000, false);
	vector<string> result(10000);
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == target)
		{
			cout << result[cur] << '\n';
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			char cmd = command[i];
			int next = Convert(cur, cmd);

			if (!visited[next])
			{
				visited[next] = true;
				result[next] = result[cur] + cmd;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n, m;
		cin >> n >> m;

		BFS(n, m);
	}

	return 0;
}
