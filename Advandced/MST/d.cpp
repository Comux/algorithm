#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 + 1;
struct Edge
{
	int u, v, w;
	bool operator < (const Edge& e) const
	{
		return this->w < e.w;
	}
} edge[N];
int ecnt = 0;

void AddEdge(int u, int v, int w)
{
	ecnt++;
	edge[ecnt].u = u;
	edge[ecnt].v = v;
	edge[ecnt].w = w;
}

int UFSet[N];

int Find(int x)
{
	if (UFSet[x] == -1) return x;
	return UFSet[x] = Find(UFSet[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	UFSet[x] = y;
}

int Kruskal(int n)
{
	sort(edge + 1, edge + ecnt + 1);
	
	int k, s, t, res = 0;
	for (int i = 1; i <= ecnt && k < n; i++)
	{
		s = Find(edge[i].u);
		t = Find(edge[i].v);
		if (s != t)
		{
			UFSet[s] = t;
			res += edge[i].w;
		}
	}
	
	return res;
}

int main()
{
	int n;
	cin >> n;
	int u, v, w;
	for (u = 1; u <= n; u++) {
		for (v = 1; v <= n; v++) {
			cin >> w;
			AddEdge(u, v, w);
		}
	}
	
	memset(UFSet, -1, sizeof(UFSet)); // must used here for the Union below
	
	int e;
	cin >> e;
	while (e-- > 0)
	{
		cin >> u >> v;
		Union(u, v);
	}

	cout << Kruskal(n);
	return 0;
}
