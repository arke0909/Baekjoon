#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int graph[100];
int cntTable[100];

void BFS() {
    queue<int> q;
    q.push(0);
    cntTable[0] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int curCnt = cntTable[cur];

        for (int i = 1; i <= 6; ++i) {
            int next = cur + i;
            if (next >= 100) continue;

            if (graph[next] != -1) next = graph[next];

            if (cntTable[next] <= curCnt + 1) continue;

            cntTable[next] = curCnt + 1;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    fill(graph, graph + 100, -1);
    fill(cntTable, cntTable + 100, 100000);

    for (int i = 0; i < n + m; ++i) {
        int start, end;
        cin >> start >> end;
        graph[start - 1] = end - 1;
    }

    BFS();

    cout << cntTable[99];
}
