#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

int r, c, k;
vector<vector<char>> map(751, vector<char>(751));
vector<vector<int>> LU(752, vector<int>(752, 0));
vector<vector<int>> RU(752, vector<int>(752, 0));
vector<vector<int>> RD(752, vector<int>(752, 0));
vector<vector<int>> LD(752, vector<int>(752, 0));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			cin >> map[i][j];
		}
	}

	// 위에서 아래로 내려가니 위에 dp 테이블을 확인
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (map[i][j] == '1')
			{
				LU[i][j] = LU[i - 1][j - 1] + 1;
				RU[i][j] = RU[i - 1][j + 1] + 1;
			}
		}
	}

	// 아래에서 위로 올라가니 아래에 dp 테이블을 확인
	for (int i = r; i > 0; --i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (map[i][j] == '1')
			{
				LD[i][j] = LD[i + 1][j - 1] + 1;
				RD[i][j] = RD[i + 1][j + 1] + 1;
			}
		}
	}

	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (map[i][j] == '1')
			{
				// 만들 수 있는 최대 크기
				int maxLength = min(LD[i][j], RD[i][j]);

				for (int l = 1; l <= maxLength; ++l)
				{
					int dy = i + 2 * l - 2;

					if (dy > r) continue;

					if (LU[dy][j] >= l && RU[dy][j] >= l)
					{
						k = max(k, l);
					}
				}
			}
		}
	}

	cout << k;
}