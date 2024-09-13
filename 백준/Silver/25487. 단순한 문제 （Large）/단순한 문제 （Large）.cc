#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, a,b,c;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a,&b,&c);
		
		a = min(a, min(b, c));
		printf("%d\n", a);
	}
	return 0;
}