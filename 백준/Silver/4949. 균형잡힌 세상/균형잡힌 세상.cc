#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	while (true)
	{
		stack<char> parentheses;
		
		bool pair = true;
		string str;
		string res;
		getline(cin, str);

		if (str == ".")
			break;

		for (auto c : str)
		{
			if (c == '('  || c == '[')
			{
				parentheses.push(c);
			}

			else if (c == ')')
			{
				if(!parentheses.empty() && parentheses.top() == '(')
				parentheses.pop();
				else
				pair = false;
			}
			else if (c == ']')
			{
				if(!parentheses.empty() && parentheses.top() == '[')
				parentheses.pop();
				else
				pair = false;
			}
		}

		res = parentheses.empty() &&  pair ? "yes\n" : "no\n";
		cout << res;


	}

	return 0;
}