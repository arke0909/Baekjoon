#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct MemberInfo
{
	int Age = 0,Idx;
	string Name = "";
};


bool compare(const MemberInfo& now, const MemberInfo& last)
{
	if (now.Age != last.Age) return now.Age < last.Age;
	return now.Idx < last.Idx;
}
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;

	cin >> n;
	MemberInfo* infos = new MemberInfo[n];

	for (int i = 0; i < n; i++)
	{
		cin >> infos[i].Age >> infos[i].Name;
		infos[i].Idx =  i;
	}

	
	sort(infos, infos + n, compare);

	for (int i = 0; i < n; i++)
	{
		cout << infos[i].Age << " " << infos[i].Name << '\n';
	}

	delete[] infos;

	return 0;
}