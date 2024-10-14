#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// cnt = 인덱스이자 요소의 개수
	int n,cnt = 0; 
	string command;
	int* queue = new int [100001];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> queue[cnt++];
		}
		else if (command == "pop")
		{
			if (cnt != 0)
			{
				cout << queue[0] << '\n';
				for (int i = 0; i < cnt - 1; i++)
				{
					queue[i] = queue[i + 1];
				}
				cnt--;
			}
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
		else if (command == "front")
		{
			if (cnt != 0)
				cout << queue[0] << '\n';
			else
				cout << "-1" << '\n';
		}
		else if (command == "back")
		{
			if (cnt != 0)
				cout << queue[cnt - 1] << '\n';
			else
				cout << "-1" << '\n';
		}
	}
}