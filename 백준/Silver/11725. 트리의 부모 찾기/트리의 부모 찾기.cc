#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int>* graph = new vector<int>[n + 1];
	int* arr = new int[n + 1];
	bool* isVisited = new bool[n + 1] {false, };

	for (int i = 0; i < n - 1; ++i)
	{
		int parent, child;
		cin >> child >> parent;

		graph[parent].push_back(child);
		graph[child].push_back(parent);
	}

	queue<int> q;

	q.push(1);

	while (!q.empty())
	{
		int curNode = q.front();

		q.pop();

		if (isVisited[curNode]) continue;

		isVisited[curNode] = true;

		for (int i = 0; i < graph[curNode].size(); ++i)
		{
			int nextNode = graph[curNode][i];

			if (!isVisited[nextNode])
			{
				arr[nextNode] = curNode;
				q.push(nextNode);
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
