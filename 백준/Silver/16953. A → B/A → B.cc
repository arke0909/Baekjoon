#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    queue<pair<int,int>> q;
    unordered_set<int> visited;

    q.push({n, 1});

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == m) {
            cout << dist;
            return 0;
        }
        if (visited.count(cur)) continue;
        visited.insert(cur);

        long long next1 = (long long)cur * 2;
        long long next2 = (long long)cur * 10 + 1;

        if (next1 <= 1000000000) q.push({(int)next1, dist + 1});
        if (next2 <= 1000000000) q.push({(int)next2, dist + 1});
    }

    cout << -1; 
    return 0;
}
