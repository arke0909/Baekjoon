#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> strs;
	string str;
	const string a = "AAAA", b = "BB";
	int idx = 0;
	bool conform = true;

	cin >> str;
	
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'X')
		{
			// X면 담을 문자열의 길이를 늘려줌
			idx++;
			if (i == str.size() - 1)
			{
				strs.push_back(str.substr(0, idx));
			}
			continue;
		}
		else if (idx == 0 && str[i] == '.')
		{
			strs.push_back(str.substr(0, 1));
			str.erase(0, 1);
			i = -1;
		}
		else
		{
			// .이면 0부터 담을 문자열의 길이만큼 벡터에 담아줌
			strs.push_back(str.substr(0, idx));
			// 이제 담은 문자열은 지워버림
			str.erase(0, idx);
			// 담을 문자열의 길이를 초기화
			idx = 0;
			i = -1;
		}
	}

	for (auto& item : strs)
	{
		if (item == ".")
			continue;

		int cnt = item.size();
		int strIdx = 0;

		if (cnt % 2 != 0)
		{
			conform = false;
			continue;
		}

		while (cnt != 0)
		{
			if (cnt >= 4)
			{
				item = item.replace(strIdx, a.size(), a);
				strIdx += 4;
				cnt -= 4;
				continue;
			}

			if (cnt >= 2)
			{
				item = item.replace(strIdx, b.size(), b);
				strIdx += 2;
				cnt -= 2;
				continue;
			}
		}
	}

	if (conform)
		for (auto item : strs)
			cout << item;
	else
		cout << -1;

}


