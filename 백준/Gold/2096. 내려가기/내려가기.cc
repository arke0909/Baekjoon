#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][4], dp_max[1001][4], dp_min[1001][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    dp_max[0][1] = dp_max[0][2] = dp_max[0][3] = 0;
    dp_min[0][1] = dp_min[0][2] = dp_min[0][3] = 0;

    dp_max[1][1] = dp_min[1][1] = arr[1][1];
    dp_max[1][2] = dp_min[1][2] = arr[1][2];
    dp_max[1][3] = dp_min[1][3] = arr[1][3];

    for (int i = 2; i <= n; ++i)
    {
        dp_max[i][1] = max(dp_max[i - 1][1], dp_max[i - 1][2]) + arr[i][1];
        dp_max[i][2] = max({ dp_max[i - 1][1], dp_max[i - 1][2], dp_max[i - 1][3] }) + arr[i][2];
        dp_max[i][3] = max(dp_max[i - 1][2], dp_max[i - 1][3]) + arr[i][3];

        dp_min[i][1] = min(dp_min[i - 1][1], dp_min[i - 1][2]) + arr[i][1];
        dp_min[i][2] = min({ dp_min[i - 1][1], dp_min[i - 1][2], dp_min[i - 1][3] }) + arr[i][2];
        dp_min[i][3] = min(dp_min[i - 1][2], dp_min[i - 1][3]) + arr[i][3];
    }

    int maxN = max({ dp_max[n][1], dp_max[n][2], dp_max[n][3] });
    int minN = min({ dp_min[n][1], dp_min[n][2], dp_min[n][3] });

    cout << maxN << ' ' << minN;
}
