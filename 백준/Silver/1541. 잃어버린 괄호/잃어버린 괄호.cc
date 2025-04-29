#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	vector<char> c;
	string str;
	int result = 0, idx = 1, total = 0;
	bool isMinus = false;
	cin >> str;

	// 숫자랑 수식 분리
	while (str.size() != 0)
	{
		int idx = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				idx = i;
				c.push_back(str[i]);
				break;
			}
			else if (i == str.size() - 1)
			{
				idx = i + 1;
				break;
			}
		}

		v.push_back(stoi(str.substr(0, idx)));
		str.erase(0, idx + 1);
	}

	// - 문자가 몇개인지 확인
	for (auto ch : c)
	{
		if (ch == '+')
		{
			if (isMinus)
			{
				total -= v[idx];
			}
			else
			{
				total += v[idx];
			}
		}
		else if (ch == '-')
		{
			total -= v[idx];
			isMinus = true;
		}

		idx++;
	}

	result = total + v[0];

	cout << result;

	return 0;
}
