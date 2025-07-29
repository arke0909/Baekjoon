#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, h, cnt = 0;
int graph[100][100][100];
int days[100][100][100];
bool isVisited[100][100][100];

struct Node {
    int x, y, z;
};

queue<Node> q;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

void BFS() {
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, z = cur.z;

        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
                continue;
            if (graph[nz][ny][nx] != 0 || isVisited[nz][ny][nx])
                continue;

            graph[nz][ny][nx] = 1;
            isVisited[nz][ny][nx] = true;
            days[nz][ny][nx] = days[z][y][x] + 1;
            q.push({ nx, ny, nz });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                cin >> graph[z][y][x];
                if (graph[z][y][x] == 1) {
                    q.push({ x, y, z });
                    isVisited[z][y][x] = true;
                }
            }
        }
    }

    BFS();

    bool flag = false;
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                cnt = max(cnt, days[z][y][x]);
                if (graph[z][y][x] == 0)
                    flag = true;
            }
        }
    }

    cout << (flag ? -1 : cnt) << '\n';
    return 0;
}
