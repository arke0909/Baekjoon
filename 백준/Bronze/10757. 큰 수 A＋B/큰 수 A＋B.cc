#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;

	bool digitsAdd = false;

	int startIdx = 0;

	cin >> a >> b;

	long long size = max(a.size(), b.size()) + 1;

	int* result = new int[size] {0};

	for (int i = a.size() - 1; i >= 0; i--)
	{
		int idx = size - (a.size() - i);
		result[idx] = a[i] - '0';
	}

	for (int i = b.size() - 1; i >= 0; i--)
	{
		int idx = size - (b.size() - i);
		result[idx] += b[i] - '0';

		

	}

	for (int i = size - 1; i > 0; i--)
	{
		if (result[i] >= 10)
		{
			result[i] -= 10;
			result[i - 1]++;
		}
	}

	if (result[0] <= 0) digitsAdd = false;
	else digitsAdd = true;

	if (digitsAdd == false) startIdx++;

	for (int i = startIdx; i < size; i++)
		cout << result[i];

	delete [] result;
}