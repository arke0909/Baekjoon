#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;int main()
{int n, num, result = 0;
stack<int> zero;

cin >> n;

while (n > 0)
{
	cin >> num;
	if (num != 0)
		zero.push(num);
	else
		zero.pop();

	n--;
}

for (int i = zero.size(); i > 0; i--)
{
	result += zero.top();
	zero.pop();
}

cout << result;
		return 0;
	}