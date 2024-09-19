#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Coordinate
{
	int X = 0,Y = 0;
};

bool Compare(const Coordinate& a, const Coordinate b)
{
	if (a.Y != b.Y) return a.Y < b.Y;
	return a.X < b.X;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;

	cin >> n;
	Coordinate *cd = new Coordinate[n];

	for (int i = 0; i < n; i++)
	{
		cin >> cd[i].X >> cd[i].Y;
	}

	sort(cd, cd + n, Compare);

	for (int i = 0; i < n; i++)
		cout << cd[i].X << ' ' << cd[i].Y << '\n';

	return 0;
}