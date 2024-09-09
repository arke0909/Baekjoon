#include <iostream>
#include <string>
using namespace std;

string str = "369";

int main()
{	
    int n,total = 0;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		s = to_string(i);
		for (int j = 0; j < s.size(); j++)
		{
			for (auto cs : str)
			{
				if (s[j] == cs) total++;
			}
		}
	}

	cout << total;

	return 0;
}