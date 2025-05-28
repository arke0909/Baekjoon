#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	vector<int> vec;
	cin >> n;

	for (int i = 0; i < n; ++i)
		vec.push_back(i + 1);

	while (vec.size() != 1)
	{
		vector<int> temp;

		for (int i = 0; i < vec.size(); ++i)
		{
			if (i % 2 != 0)
				temp.push_back(vec[i]);
		}

		vec = temp;
	}

	cout << vec[0];
}


