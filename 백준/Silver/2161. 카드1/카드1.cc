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
	queue<int> q;
	cin >> n;

	for (i = 0; i < n; ++i)
		q.push(i + 1);

	while (q.size() != 1)
	{
		cout << q.front() << ' ';
		q.pop();

		v = q.front();
		q.pop();
		q.push(v);
	}

	cout << q.front();

}