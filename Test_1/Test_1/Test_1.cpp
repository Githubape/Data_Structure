#include<cstdio>
using namespace std;

struct node
{
	int data;
	int val;
	node* next;
};

const int maxn = 20010;
const int INF = 100000000;
int n;
int e;
int d[maxn];
int vis[maxn] = { 0 };
node* G[maxn];

void insert(node* pre, node* Node)
{
	if (pre->next = NULL)
	{
		pre->next = Node;
	}
	else
	{
		Node->next = pre->next;
		pre->next = Node;
	}
}

void Dijkstra(int s)
{
	d[s] = 0;
	int v;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		int MIN = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == 0 && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = 1;
		node* Node = G[u];
		while (Node)
		{
			v = Node->data;
			if (vis[v] == 0 && d[u] + Node->val < d[v])
			{
				d[v] = d[u] + Node->val;
			}
			Node = Node->next;
		}
	}
}


void push(int v1, int v2, int val)
{
	node* Node = new node;
	node* pre = G[v1];
	Node->data = v2;
	Node->val = val;
	Node->next = NULL;
	if (!G[v1]) G[v1] = Node;
	else if (pre->data > Node->data)
	{
		Node->next = G[v1];
		G[v1] = Node;
	}
	else
	{
		while (pre->next)
		{
			if (pre->next->data > Node->data) break;
			pre = pre->next;
		}
		insert(pre, Node);
	}
}

int main()
{
	scanf_s("%d%d", &n, &e);
	for (int i = 0; i < n; i++) d[i] = INF;
	int v1, v2, val;
	node* Node;
	for (int i = 0; i < e; i++)
	{
		scanf_s("%d%d%d", &v1, &v2, &val);
		push(v1, v2, val);
	}

	Dijkstra(0);

	for (int i = 1; i < n; i++)
	{
		if (d[i] != INF)
		{
			printf("%d ", d[i]);
		}
	}

	return 0;
}

/*

4 4
0 1 1
0 3 1
1 3 1
2 0 1

*/
