#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct WH
{
	int Weight = 0,Height = 0,Idx;
};


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, grade[50];

	cin >> n;
	WH infos[50];

	for (int i = 0; i < n; i++)
	{
		cin >> infos[i].Weight >> infos[i].Height;
		infos[i].Idx = i;
		grade[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (infos[i].Idx == infos[j].Idx) continue;
			if (infos[i].Height < infos[j].Height && infos[i].Weight < infos[j].Weight) grade[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << grade[i] << ' ';
	return 0;
}