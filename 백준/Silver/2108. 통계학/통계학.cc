#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
using std::cout;

int main()
{
	// 수의 개수, 최빈값을 찾는데 쓰일 인덱스, 가장 많이 나온 횟수, 최빈값이 2개 이상이라면 몇번째 최빈값인지 판단할 정수
	int n, modeIdx = 0, maxMode = 0, modeCnt = 0,
		//가장 작은 값, 가장 큰 값
		min, max;

	//산술평균에 쓰일 총합값
	double total = 0;

	// 최빈값이 두개 이상인지 판단할 불리언 값
	bool isOneMore = false;

	// 최빈값을 찾는데 사용될 맵
	map<int, int> modeMap;

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		total += num;

		modeMap[num]++;

		if (maxMode < modeMap[num])
		{
			maxMode = modeMap[num];
			isOneMore = false;
		}
		else if (maxMode == modeMap[num])
			isOneMore = true;
	}

	sort(arr, arr + n);

	int before = -4001;

	for (int i = 0; i < n; i++)
	{
		if (maxMode == modeMap[arr[i]])
		{
			if (isOneMore)
			{
				if (before == arr[i]) continue;
				if (modeCnt > 0)
				{
					modeIdx = i;
					break;
				}

				modeCnt++;
			}
			else
			{
				modeIdx = i;
				break;
			}
		}

		before = arr[i];
	}

	int arithmetic = round(total / n);

	cout << (arithmetic == 0.0f ? 0 : arithmetic) << '\n';
	cout << arr[n / 2] << '\n';
	cout << arr[modeIdx] << '\n';
	cout << abs(arr[0] - arr[n - 1]) << '\n';

	delete[] arr;
	return 0;
}