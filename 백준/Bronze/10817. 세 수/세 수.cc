#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	vector<int> vec;
	for (int i = 0; i < 3; ++i)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}
	sort(vec.begin(), vec.end());
	cout << vec[1];
}


