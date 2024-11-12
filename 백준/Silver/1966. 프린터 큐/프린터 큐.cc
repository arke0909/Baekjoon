#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	// 테스트 케이스, 문서의 개수, 몇번째 문서
	int tc, n, m;

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		// 각 문서들의 중요도를 담아줄 우선순위 큐
		priority_queue<int> pq;
		// pair에 중요도와 인덱스를 담아주고, pair들을 담아줄 큐
		queue<pair<int, int>> q;

		int cnt = 1;
		cin >> n >> m;

		for (int j = 0; j < n; j++)
		{
			int priority;
			cin >> priority;
			pq.push(priority);
			q.push({ priority, j });
		}

		// 비어있지않을 동안
		while (!q.empty())
		{
			// 현재 문서의 중요도
			int currentPriority = q.front().first;
			// 현재 문서 인덱스
			int currentIdx = q.front().second;

			// 만약 현재 문서의 중요도가 가장 높다면
			if (currentPriority == pq.top())
			{
				// 현재 문서 인덱스가 찾고싶던 문서라면 반복문 종료
				if (currentIdx == m) break;

                // 아니라면 가장 높은 중요도를 가진 문서를 출력(제거)한다.
				q.pop();
				pq.pop();
				cnt++;
				continue;
			}

			//첫번째 문서를 맨 마지막으로 보내고 현재 문서 인덱스와 중요도 갱신과 횟수 증가
			q.push(q.front());
			q.pop();
		}

		cout << cnt << '\n';
	}

	return 0;
}