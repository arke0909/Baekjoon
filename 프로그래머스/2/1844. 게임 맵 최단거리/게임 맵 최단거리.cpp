#include<vector>
#include<queue>
using namespace std;

struct Node {
    int x;
    int y;
    int dist;
};

int solution(vector<vector<int> > maps)
{
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1, 0,0 };

    int n = maps.size();
    int m = maps[0].size();
    int INF = 10000;
    int** dist = new int* [n];

    for (int i = 0; i < n; ++i)
    {
        dist[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            dist[i][j] = INF;
        }
    }

    dist[0][0] = 1;
    queue<Node> q;
    q.push({ 0,0,1 });

    while (!q.empty())
    {
        Node curNode = q.front();
        q.pop();

        int cx = curNode.x;
        int cy = curNode.y;
        int cd = curNode.dist;

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nd = cd + 1;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if (maps[ny][nx] == 0) continue;

            if (dist[ny][nx] > nd)
            {
                dist[ny][nx] = nd;
                q.push({ nx,ny,nd });
            }
        }
    }

    int answer = dist[n - 1][m - 1];

    if (answer == INF)
        return -1;

    return answer;
}