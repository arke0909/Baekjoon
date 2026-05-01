#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool IsPrime(int x)
{
    if(x <= 1) return false;
    for (int i = 2; i < x; i++) 
    {
		if (x % i == 0)
        {
			return false;
        }
	}
    
	return true;
}

int BackTracking(int x, int size, string numbers, vector<bool>& isVisited, set<int>& used)
{
    if(x == 0) return 0;
    
    int cnt = 0;
    
    if(IsPrime(x) && used.find(x) == used.end())
    {
        cnt++;
        used.insert(x);        
    }
    
    if(size == numbers.size()) return cnt;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(isVisited[i]) continue;
        
        isVisited[i] = true;
        int next = x * 10 + numbers[i] - '0'; 
        cnt += BackTracking(next, size + 1, numbers, isVisited, used);
        isVisited[i] = false;
    }
    
    return cnt;
}

int solution(string numbers) {
    int answer = 0;

    vector<bool> isVisited(numbers.size(), false);
    set<int> used;
    for(int i = 0; i < numbers.size(); ++i)
    {
        isVisited[i] = true;
        answer += BackTracking(numbers[i] - '0', 1, numbers, isVisited, used);
        isVisited[i] = false;
    }
    
    return answer;
}