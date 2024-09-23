#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,num;
	
	map<int, int> card;

	cin >> n;
	int *N = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
		card[N[i]]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if (card.find(num) != card.end())
			cout << card[num] << ' ';
		else
			cout << "0 ";
	}

	return 0;
}