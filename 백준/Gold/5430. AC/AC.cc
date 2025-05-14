#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, v, i, j;
	bool isConform, isReverse;
	deque<int> dq;
	string command, contant, number;

	cin >> n;
	for (i = 0; i < n; ++i)
	{
		dq.clear();
		isConform = true;
		isReverse = false;
		number = "";
		cin >> command >> v >> contant;

		for (j = 1; j < contant.size(); ++j)
		{
			if (contant[j] == ',' || contant[j] == ']')
			{
				if (number != "")
				{
					dq.push_back(stoi(number));
					number = "";
				}
			}
			else
			{
				number += contant[j];
			}
		}

		for (j = 0; j < command.size(); ++j)
		{
			if (command[j] == 'R')
			{
				isReverse = !isReverse;
			}
			else if (command[j] == 'D')
			{
				if (!dq.empty())
				{
					if (isReverse)
						dq.pop_back();
					else
						dq.pop_front();
				}
				else
				{
					isConform = false;
					break;
				}
			}
		}

		if (isConform)
		{
			cout << '[';
			if (!isReverse)
				for (j = 0; j < dq.size(); ++j)
				{
					cout << dq[j];

					if (j != dq.size() - 1)
						cout << ',';
				}
			else
			{
				for (j = dq.size() - 1; j >= 0; --j)
				{
					cout << dq[j];

					if (j != 0)
						cout << ',';
				}
			}
			cout << "]\n";
		}
		else
			cout << "error\n";
	}
}