#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j % 2 == 0)
                {
                    cout << '*';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << '\n';
        }
        else
        {
            for (int j = 0; j < m; ++j)
            {
                if (j % 2 == 0)
                {
                    cout << '.';
                }
                else
                {
                    cout << '*';
                }
            }
            cout << '\n';
        }
    }
}
