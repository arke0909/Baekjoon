#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

int n, m, answer = 1000000;
vector<vector<int>> map;
vector<pair<int,int>> chickenShops;
vector<pair<int,int>> homes;
vector<pair<int,int>> selectedChickenShops;

// 치킨집 선정
void Backtracking(int idx, int chickenShop)
{
	if (chickenShop == m)
	{
		int total = 0;

		// 치킨집 거리 구하기
		for (auto home : homes)
		{
			int dist = 51;
			
			for (auto chickenShop : selectedChickenShops)
			{
				dist = min(dist, abs(chickenShop.first - home.first) + abs(chickenShop.second - home.second));
			}

			total += dist;
		}

		answer = min(total, answer);
		return;
	}

	for (int i = idx; i < chickenShops.size(); ++i)
	{
		selectedChickenShops.push_back(chickenShops[i]);
		Backtracking(i + 1, chickenShop + 1);
		selectedChickenShops.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map = vector(n + 1, vector<int>(n + 1, 0));

	// 입력
	for(int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				chickenShops.push_back({ j, i });
			else if (map[i][j] == 1)
				homes.push_back({ j, i });
		}

	
	Backtracking(0, 0);

	cout << answer;
}