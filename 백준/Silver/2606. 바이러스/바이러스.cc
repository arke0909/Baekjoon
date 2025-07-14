#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int>* graph;
bool* isVisit;

int dfs(int x)
{
	int cnt = 0;
	isVisit[x] = true;
	for (int i = 0; i < graph[x].size(); ++i)
	{
		int y = graph[x][i];
		if (!isVisit[y])
		{
			cnt++;
			cnt += dfs(y);
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, number, cnt = 0;
	cin >> n >> number;
	graph = new vector<int>[n];
	isVisit = new bool[n] {false};

	for (int i = 0; i < number; ++i)
	{
		int x, y;
		cin >> x >> y;

		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}

	for (int i = 0; i < n; ++i)
		sort(graph[i].begin(), graph[i].end());

	// 인덱스는 0번째부터 시작해서
	cout << dfs(0);
}
