#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, root[32000]{ 0 };
bool flag = true;
vector<int> graph[32000], save;

void TopologySort()
{
    queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        if (root[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        save.push_back(v + 1);

        for (int i = 0; i < graph[v].size(); ++i)
        {
            root[graph[v][i]]--;

            if (root[graph[v][i]] == 0)
                q.push(graph[v][i]);

        }
    }

    flag = save.size() == n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int v;
        vector<int> temp;
        cin >> v;
        for (int j = 0; j < v; ++j)
        {
            int a;
            cin >> a;
            temp.push_back(a - 1);
        }
        for (int j = 0; j < temp.size(); ++j)
        {
            for (int k = j + 1; k < temp.size(); ++k)
            {
                graph[temp[j]].push_back(temp[k]);
                root[temp[k]]++;
            }
        }
    }

    TopologySort();

    if (flag)
    {
        for (auto item : save)
            cout << item << '\n';
    }
    else
        cout << 0;
}