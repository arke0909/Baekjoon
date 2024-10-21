#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str, res;
		bool pair = true;
		stack<char> parentheses;

		cin >> str;

		for (auto c : str)
		{
			if (c == '(')
			{
				parentheses.push(c);
			}

			else if (c == ')')
			{
				if (!parentheses.empty() && parentheses.top() == '(')
					parentheses.pop();
				else
					pair = false;
			}
		}

		res = parentheses.empty() && pair ? "YES\n" : "NO\n";
		cout << res;
	}

	

	return 0;
}