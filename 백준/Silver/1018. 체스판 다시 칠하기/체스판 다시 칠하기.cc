#include <iostream>
#include <string>
using namespace std;

string board1[] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};
string board2[] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};
int main()
{

	int cnt = 0,cntB =0, cntW = 0, N, M, maxNum = 64;

	cin >> N >> M;
	string board[50];

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			for (int n = 0; n < 8; n++)
			{
				for (int m = 0; m < 8; m++)
				{
					if (board[n + i][m + j] != board1[n][m])
					{
						cntB++;
					}
					else if (board[n + i][m + j] != board2[n][m])
					{
						cntW++;
					}
				}
			}
			cnt = min(cntB, cntW);
			if (maxNum > cnt)
			{
				maxNum = cnt;
			}
			cntB = 0;
			cntW = 0;
		}
	}
	
	cout << maxNum;

	return 0;
}