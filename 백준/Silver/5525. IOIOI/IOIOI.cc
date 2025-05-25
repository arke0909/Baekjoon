#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, result = 0, i = 0, cnt = 0;
    string s;
    cin >> n >> m >> s;


    while (i < m - 1)
    {
        if (s[i] == 'I')
        {
            cnt = 0;
            while (i + 2 < m && s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                cnt++;
                i += 2;
                if (cnt >= n) result++;
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    cout << result;
}
