#include "iostream"
#include "vector"
#include "queue"
#include "unordered_map"
#include "algorithm"
using namespace std;

int n, cnt = 0;
vector<int> col(15, 0);

bool Check(int r)
{
	for (int i = 1; i < r; ++i)
	{
		if (col[r] == col[i] || (abs(r - i) == abs(col[r] - col[i])))
			return false;
	}

	return true;
}

// 한 행에 하나의 퀸만 배치
void BackTracking(int r)
{
	if (r > n)
	{
		cnt++;
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		col[r] = i;
		if(Check(r))
			BackTracking(r + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	BackTracking(1);

	cout << cnt;
}