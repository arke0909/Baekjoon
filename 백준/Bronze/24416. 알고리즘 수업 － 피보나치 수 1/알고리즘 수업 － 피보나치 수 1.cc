#include<iostream>
using namespace std;

int f[41];
int cnt1 = 1, cnt2;

int fib1(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
	{
		cnt1++;
		return (fib1(n - 1) + fib1(n - 2));
	}
}
int fib2(int n)
{
	f[1] = f[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		cnt2++;
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

int main()
{
	int n;
	cin >> n;

	fib1(n);
	fib2(n);

	cout << cnt1 << ' ' << cnt2;
}


