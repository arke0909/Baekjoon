#include "iostream"
#include "vector"
#include "queue"
#include "stack"
#include "unordered_map"
#include "algorithm"
using namespace std;

string str, bomb, emptyStr = "FRULA", result;
stack<char> stk;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> bomb;

	for (char c : str) {
		result += c;

		if (result.size() >= bomb.size())
		{
			if (result.substr(result.size() - bomb.size()) == bomb) 
			{
				result.erase(result.size() - bomb.size());
			}
		}
	}

	if (result.empty())
		cout << emptyStr;
	else
		cout << result;
}