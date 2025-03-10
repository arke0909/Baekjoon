#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 가능한지 확인할 불리언 값
	bool isCan = true;
	// 몇번째 수까지, 현재 인덱스
	int n, numIdx = 0, arrIdx = 0;
	// 실제로 연산할 스택
	stack<int> stk;
	// 출력할 문자들을 담아둘 큐
	queue<char> result;

	cin >> n;

	// 수열을 담을 배열
	int* arr = new int[n];
	// 1 ~ n까지의 수를 담을 배열
	int* num = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		num[i] = i + 1;
	}


	while (arrIdx < n)
	{
		int target = arr[arrIdx];

		// 스택의 맨 위가 타겟이라면
		if (stk.size() != 0 && stk.top() == target)
		{
			// 실제 스택에서 제거하고 다음 타겟으로 넘어가고 출력할 문자를 큐에 담아준다.
			stk.pop();
			arrIdx++;
			result.push('-');

			continue;
		}
		// 아니라면 or 모든 숫자를 넘어갔다면
		else if(numIdx < n)
		{
			// 실제 스택에 담아주고 다음 숫자로 넘어간다, 출력할 문제를 큐에 담아준다.
			stk.push(num[numIdx]);
			numIdx++;
			result.push('+');

			continue;
		}

		// 불가능으로 설정
		isCan = false;
		break;
	}

	// 불가능하다면 NO를 출력
	if (!isCan)
		cout << "NO";
	// 가능하다면 모든 문자를 출력한다.
	else
		while (!result.empty())
		{
			cout << result.front() << '\n';
			result.pop();
		}


	return 0;
}	