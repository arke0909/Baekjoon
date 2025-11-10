#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int x;
	int y;
	int cost;
};

const int INF = 2147483647;
int cave[125][125];
int length[125][125];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
queue<Node> q;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t = 0;

	while (true)
	{
		t++;
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				cin >> cave[i][j];
				length[i][j] = INF;
			}

		length[0][0] = 0;
		q.push({ 0,0,cave[0][0]});

		while (!q.empty())
		{
			int curX = q.front().x;
			int curY = q.front().y;
			int cost = q.front().cost;

			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = curX + dx[i];
				int ny = curY + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				int nc = cost + cave[ny][nx];

				if (length[ny][nx] > nc)
				{
					length[ny][nx] = nc;
					q.push({ nx,ny,nc });
				}
			}
		}

		cout << "Problem " << t << ": " << length[n - 1][n - 1] << '\n';
	}

}
