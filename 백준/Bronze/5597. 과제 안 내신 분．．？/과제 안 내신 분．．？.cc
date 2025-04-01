#include<iostream>
using namespace std;

int main()
{
	int students[30]{0};

	for (int i = 0; i < 28; i++)
	{
		int idx;
		cin >> idx;

		students[idx - 1]++;
	}


	for (int i = 0; i < 30; i++)
	{
		if (students[i] == 0)
			cout << i + 1 << '\n';
	}

	/*int n, min = 2147483647;

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int target = arr[i];

		for (int j = 0; j < n; j++)
		{
			int temp = arr[j];

			if (temp == target) continue;

			if (target < temp)
			{
				int dummy = target;
				target = temp;
				temp = dummy;
			}

			int diff = target - temp;

			if (diff < min)
				min = diff;
		}
	}

	cout << min;*/
}