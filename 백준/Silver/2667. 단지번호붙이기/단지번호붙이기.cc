#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt = 0;
bool** isVisited;
char** graph;
vector<int> results;

int DFS(int x, int y)
{
	int cnt = 1;
	if (y < 0 || y >= n || x < 0 || x >= n) return 0;

	if (isVisited[y][x]) return 0;
	isVisited[y][x] = true;

	if (graph[y][x] == '0') return 0;
	graph[y][x] = '0';

	cnt += DFS(x + 1, y);
	cnt += DFS(x - 1, y);
	cnt += DFS(x, y + 1);
	cnt += DFS(x, y - 1);

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	graph = new char* [n];
	isVisited = new bool* [n];

	for (int i = 0; i < n; ++i)
	{
		graph[i] = new char[n];
		isVisited[i] = new bool[n] {false};
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (graph[i][j] == '1')
			{
				cnt++;
				results.push_back(DFS(j, i));
			}
		}
	}

	cout << cnt << '\n';
	sort(results.begin(), results.end());
	for (auto item : results)
		cout << item << '\n';
}