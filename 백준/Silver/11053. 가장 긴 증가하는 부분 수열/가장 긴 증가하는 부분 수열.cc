#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,cnt = 0, arr[1000], lis[1000], idx = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	lis[0] = arr[0];

	for (int i = 1; i < n; ++i)
	{
		if (lis[idx] < arr[i])
		{
			lis[idx + 1] = arr[i];
			idx++;
		}
		else
		{
			int left = 0, right = idx, target = arr[i];

			while (left < right)
			{
				int mid = (left + right) / 2;

				if (lis[mid] < target)
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}

			lis[right] = arr[i];
		}
	}

	cout << idx + 1;
}