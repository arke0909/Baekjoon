#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int zeroCnt = 0, oneCnt = 0, strSize;
    char zero = '0', one = '1';
    string str, zeroS, oneS;
    cin >> str;

    strSize = str.size();
    zeroS = oneS = str;

    // 전부 0으로 맞추기
    for (int i = 0; i < strSize; ++i)
    {
        if (zeroS[i] != zero)
        {
            int start = i;
            zeroS[i] = zero;
            while (start + 1 < strSize && zeroS[start + 1] != zero)
            {
                zeroS[start + 1] = zero;
                start++;
            }
            zeroCnt++;
        }
    }
    // 전부 1으로 맞추기
    for (int i = 0; i < strSize; ++i)
    {
        if (oneS[i] != one)
        {
            int start = i;
            oneS[i] = one;
            while (start + 1 < strSize && oneS[start + 1] != one)
            {
                oneS[start + 1] = one;
                start++;
            }
            oneCnt++;
        }
    }

    cout << min(zeroCnt, oneCnt);

    return 0;
}