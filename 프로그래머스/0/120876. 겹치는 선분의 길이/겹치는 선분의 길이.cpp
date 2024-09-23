#include <string>
#include <vector>

using namespace std;

int cnt[201];

int solution(vector<vector<int>> lines) {
    int answer = 0;

    for (int i = 0; i < 3; i++)
    {
       for (int j = lines[i][0] + 100; j < lines[i][1] + 100; j++)
            cnt[j]++;
    }

    for (auto item : cnt)
        if (item >= 2) answer++;

    return answer;
}