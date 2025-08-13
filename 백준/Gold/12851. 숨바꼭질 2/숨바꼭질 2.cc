#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int x, k, INF = 100000000;
int mins[100001];      // 최소 거리
long long ways[100001]; // 경우의 수
vector<pair<int, int>> graph[100001];

void Dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (mins[current] < distance) continue;

        for (int next : {current * 2, current - 1, current + 1})
        {
            if (next < 0 || next > 100000) continue;

            int nextDistance = distance + 1;

            if (mins[next] > nextDistance) 
            {
                mins[next] = nextDistance;
                ways[next] = ways[current]; 
                pq.push({ nextDistance, next });
            }
            else if (mins[next] == nextDistance)
            {
                ways[next] += ways[current];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> k;

    fill(mins, mins + 100001, INF);
    fill(ways, ways + 100001, 0);

    mins[x] = 0;
    ways[x] = 1; 

    if (x <= k)
    {
        Dijkstra(x);
        cout << mins[k] << '\n' << ways[k];
    }
    else
    {
        cout << x - k << '\n' << 1;
    }
}
