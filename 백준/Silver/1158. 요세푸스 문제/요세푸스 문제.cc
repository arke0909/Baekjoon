#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int n, m, idx = 1;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		q.push(i);

	cout << '<';

	while (q.size() != 1)
	{
		if (idx == m)
		{
			cout << q.front() << ", ";
			q.pop();
			idx = 1;
		}
		else
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
			idx++;
		}
	}

	cout << q.front() << '>';

	return 0;
}
