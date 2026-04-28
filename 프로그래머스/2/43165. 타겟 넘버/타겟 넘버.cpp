#include <string>
#include <vector>

using namespace std;

int dfs(int idx, vector<int> numbers, int target, int current)
{
    int cnt = 0;

    if (idx == numbers.size() && target == current) return 1;
    if (idx >= numbers.size()) return 0;

    cnt += dfs(idx + 1, numbers, target, current + numbers[idx]);
    cnt += dfs(idx + 1, numbers, target, current - numbers[idx]);

    return cnt;
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(0, numbers, target, 0);
    return answer;
}
