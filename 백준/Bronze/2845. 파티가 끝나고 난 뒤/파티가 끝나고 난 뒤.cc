#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	vector<int> vec;
	int l, p;
	cin >> l >> p;

	for (int i = 0; i < 5; ++i)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}

	for (auto item : vec)
	{
		int v = l * p;
		cout << item - v << ' ';
	}
}


