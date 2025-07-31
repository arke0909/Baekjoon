#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, W, H, L;
    cin >> N >> W >> H >> L;

    int cows_per_row = W / L;
    int rows = H / L;

    int max_cows = cows_per_row * rows;

    cout << min(N, max_cows) << endl;

    return 0;
}
