#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> tree(1000001);

void Order(int root, int node)
{
	if (root < node)
	{
		if (tree[root].second != 0)
		{
			Order(tree[root].second, node);
		}
		else
		{
			tree[root].second = node;
		}
	}
	else
	{
		if (tree[root].first != 0)
		{
			Order(tree[root].first, node);
		}
		else
		{
			tree[root].first = node;
		}
	}
}

void OrderWrite(int root)
{
	if (tree[root].first != 0)
		OrderWrite(tree[root].first);
	if (tree[root].second != 0)
		OrderWrite(tree[root].second);
	cout << root << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node, root = 0;

	while (cin >> node)
	{
		// 루트 노드가 비었을 때
		if (root == 0)
		{
			root = node;
		}
		// 루트 노드가 존재할 때
		else
		{
			Order(root, node);
		}
	}

	OrderWrite(root);
}