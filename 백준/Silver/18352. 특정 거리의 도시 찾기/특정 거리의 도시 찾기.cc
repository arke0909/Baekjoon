#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int p;
	int v;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vec(300001);
	int n, m, k, x, INF = 10000000;
	vector<int> flag(300001, INF), answer;
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;

		vec[start].push_back(end);
	}

	flag[x] = 0;

	queue<Node> q;

	q.push({ x, 0 });

	while (!q.empty())
	{
		int curP = q.front().p;
		int curV = q.front().v;

		q.pop();

		int nv = curV + 1;
		for (auto item : vec[curP])
		{
			if (flag[item] > nv)
			{
				if (nv == k)
				{
					answer.push_back(item);
				}

				flag[item] = nv;
				q.push({ item, nv });
			}
		}
	}

	sort(answer.begin(), answer.end());

	if (answer.empty())
		cout << -1;
	else
		for (auto item : answer)
		{
			cout << item << '\n';
		}

}
