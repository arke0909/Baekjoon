#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> pq;
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		pq.push(-v);
	}

	if (pq.size() != 1)
	{
		while (!pq.empty())
		{
			int first = -pq.top();
			pq.pop();
			int second = -pq.top();
			pq.pop();

			int temp = first + second;

			cnt += temp;

			if (pq.empty()) break;

			pq.push(-temp);
		}

		cout << cnt;
	}
	else
		cout << 0;

	
}