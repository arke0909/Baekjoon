#include <iostream>
using namespace std;

int main()
{
	int arr[13]{0}, m, result, idx;

	for (int i = 0; i < 13; ++i)
	{
		char num;
		cin >> num;
		if (num != '*')
			arr[i] = num - '0';
		else
			idx = i;
	}

	int total = arr[12];
	
	for(int i = 0; i < 10; ++i)
	{
		arr[idx] = i;

		int target = 10 - (arr[0] + (3 * arr[1]) + arr[2] + (3 * arr[3]) + arr[4] + (3 * arr[5]) + arr[6] + (3 * arr[7]) + arr[8] + (3 * arr[9]) + arr[10] + (3 * arr[11])) % 10;
		
		target = target == 10 ? 0 : target;

		if (total == target)
			break;
	}

	cout << arr[idx];
}
