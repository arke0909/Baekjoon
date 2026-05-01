#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < scoville.size(); ++i)
    {
        minHeap.push(scoville[i]);
    }
    
    
    while(true)
    {
        // 모든 음식이 k를 넘는지 확인
        bool flag = minHeap.top() < K;
        
        // 넘지 않으면 새로운 음식 만들기
        if(flag)
        {
            if(minHeap.size() < 2) return -1;
            
            int food1 = minHeap.top();
            minHeap.pop();
            int food2 = minHeap.top();
            minHeap.pop();
            
            int newFood = food1 + 2 * food2;
            minHeap.push(newFood);
            
            answer++;
            continue;
        }
        
        break;
    }
    
    
    return answer;
}