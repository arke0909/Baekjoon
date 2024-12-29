#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트케이스 개수
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		// x, y, 이동한 횟수
		int x, y, cnt = 1, sqr = 1;

		cin >> x >> y;

		// x와 y의 거리
		int distance = y - x;

		while (distance > pow(sqr, 2))
		{
			// 제곱수를 넘어갈 때 마다 카운트 증가
			if (distance > pow(sqr, 2))
			{
				cnt++;
				sqr++;
			}

			float sqnA = pow(sqr - 1, 2);
			float sqnB = pow(sqr, 2);

			// 제곱수의 중간값을 넘어갈 때 마다 카운트 증가
			if (distance >= round(sqnA + sqnB) / 2)
				cnt++;
		}

		cout << cnt << "\n";
	}
	return 0;
}