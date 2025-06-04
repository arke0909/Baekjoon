#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		
		for (int j = 0; j < name.size(); j++)
		{
			if (name[j] < 97)
				name[j] += 32;

			cout << name[j];
		}
		cout << '\n';
	}
}


