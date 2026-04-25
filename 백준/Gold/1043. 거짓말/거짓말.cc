#include "iostream"
#include "vector"
#include "queue"
#include "unordered_map"
#include "algorithm"
using namespace std;

int n, m, known, cnt = 0;
vector<int> people(51);
vector<bool	> knownList(51);
vector<int> parties(51);

int Find(int x)
{
	if (people[x] == x)
		return x;
	return people[x] = Find(people[x]);
}

void Union(int x, int y)
{
	int xd = Find(x);
	int yd = Find(y);

	if (xd > yd)
	{
		people[xd] = yd;
	}
	else
	{
		people[yd] = xd;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> known;
	cnt = m;

	for (int i = 1; i <= n; ++i)
	{
		people[i] = i;
	}

	for (int i = 0; i < known; ++i)
	{
		int	who;
		cin >> who;
		knownList[who] = true;
	}

	// 파티 정보 입력
	for (int i = 1; i <= m; ++i)
	{
		int	visitors;
		cin >> visitors;

		int reader;
		cin >> reader;
		parties[i] = reader;

		for (int j = 1; j < visitors; ++j)
		{
			int w;
			cin >> w;

			Union(w, reader);
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		int reader = Find(parties[i]);

		bool flag = false;

		for (int j = 1; j <= n;++j)
		{
			if (knownList[j] && Find(j) == reader)
			{
				flag = true;
				break;
			}
		}

		if (flag)
			cnt--;
	}

	cout << cnt;
}