#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int arr[5], result = 1;

	for (int i = 0; i < 5; ++i)
		cin >> arr[i];

	while (true)
	{
		int cnt = 0;
		for (int i = 0; i < 5; ++i)
			if (result % arr[i] == 0) cnt++;

		if (cnt >= 3) break;

		result++;
	}
	cout << result;
}