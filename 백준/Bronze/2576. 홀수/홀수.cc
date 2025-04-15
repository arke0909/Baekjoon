#include <iostream>
using namespace std;

int main()
    {
    int total = 0, minV = 100;
    for(int i = 0; i < 7; ++i)
    {
        int v;
       cin >> v;
        if(v % 2 != 0)
            {
        minV = min(minV, v);
       total += v;
            }
    }
    if (minV != 100)
    cout << total << '\n' << minV;
    else 
        cout << -1;
}