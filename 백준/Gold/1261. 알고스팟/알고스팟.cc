#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int dist[101][101];
char mp[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
const int INF = 2147483647;

void Dijkstra(int sx, int sy) {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    dist[sy][sx] = 0;
    pq.push({0, sx, sy});

    while (!pq.empty()) {
        auto [curDist, x, y] = pq.top();
        pq.pop();

        if (curDist > dist[y][x]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > m || ny > n) continue;

            int cost = (mp[ny][nx] == '1') ? 1 : 0;
            int nextDist = curDist + cost;

            if (dist[ny][nx] > nextDist) {
                dist[ny][nx] = nextDist;
                pq.push({nextDist, nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    for (int i = 1; i <= n; i++)
        fill(dist[i], dist[i] + m + 1, INF);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];

    Dijkstra(1, 1);

    cout << dist[n][m] << "\n";
    return 0;
}
