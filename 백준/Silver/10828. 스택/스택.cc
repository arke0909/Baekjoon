#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n,cnt = 0; 
	stack <int> a;
	string command;
	int* stackA = new int [99999];

	cin >> n;//sipal

	for (int i = 0; i < n; i++)
	{
		cin >> command;
		//command = "push";

		if (command == "push")
		{
			//stackA[cnt++] = 2;
			cin >> stackA[cnt++];
		}
		else if (command == "pop")
		{
			if (cnt != 0)
				cout << stackA[--cnt] << '\n';
			else
				cout << "-1" << '\n';
		}
		else if (command == "size")
		{
			cout << cnt << '\n';
		}
		else if (command == "empty")
		{
			cout << (int)(cnt == 0) << '\n';
 		}
		else if (command == "top")
		{
			if (cnt != 0)
				cout << stackA[cnt - 1] << '\n';
			else
				cout << "-1" << '\n';
		}
	}
}