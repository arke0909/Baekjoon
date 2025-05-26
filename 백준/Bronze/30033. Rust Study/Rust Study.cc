#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	vector<int> vec;
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;

		if (vec[i] <= v)
			cnt++;
	}

	cout << cnt;
}


