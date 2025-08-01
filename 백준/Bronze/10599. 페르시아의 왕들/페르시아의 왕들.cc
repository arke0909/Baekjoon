#include <iostream>
using namespace std;

int main() {
    while (true) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == 0 && b == 0 && c == 0 && d == 0)
            break;

        int min_age = c - b;
        int max_age = d - a;

        cout << min_age << " " << max_age << '\n';
    }

    return 0;
}
