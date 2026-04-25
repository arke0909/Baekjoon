#include "iostream"
#include "vector"
#include "queue"
#include "unordered_map"
#include "algorithm"
using namespace std;

int n, answer = 0, farNode;
vector<vector<pair<int, int>>> edges(10001);
vector <bool> isVisit(10001);

void DFS(int from, int weight)
{
	isVisit[from] = true;

	if (weight > answer)
	{
		answer = weight;
		farNode = from;
	}

	for (auto item : edges[from])
	{
		if (isVisit[item.first]) continue;

		DFS(item.first, weight + item.second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i < n; ++i)
	{
		int from, to, weight;
		cin >> from >> to >> weight;

		edges[from].push_back({to, weight});
		edges[to].push_back({from, weight});
	}

	DFS(1, 0);
	isVisit.assign(n + 1, false);

	DFS(farNode, 0);

	cout << answer;
}