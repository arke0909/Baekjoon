#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> inputVec(n), pressVec;

	for (int i = 0; i < n; ++i)
		cin >> inputVec[i];

	pressVec = inputVec;

	sort(pressVec.begin(), pressVec.end());
	pressVec.erase(unique(pressVec.begin(), pressVec.end()), pressVec.end());

	for (int i = 0; i < n; ++i)
	{
		int idx = lower_bound(pressVec.begin(), pressVec.end(), inputVec[i]) - pressVec.begin();
		cout << idx << ' ';
	}
}