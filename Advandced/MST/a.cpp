#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int E = 1000;
int par[E];
struct Edge
{
	int u, v, w;
	bool operator<(const Edge& e) const
	{
		return this->w < e.w;
	}
} edge[E << 1];
int ecnt = 0;

void AddEdge(int u, int v, int w)
{
	ecnt++;
	edge[ecnt].u = u;
	edge[ecnt].v = v;
	edge[ecnt].w = w;
}

int Find(int x)
{
	if (par[x] == -1) return x;
	return par[x] = Find(par[x]);
}

bool Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return false; 
	par[x] = y;
	return true;
}

int Kruskal(int n)
{
	memset(par, -1, sizeof(par));
	sort(edge + 1, edge + ecnt + 1); // [1..ecnt]

	int k, s, t;
	int ans = 0;
	for (int i = 1; i <= ecnt && k < n-1; i++)
	{
		if (Union(edge[i].u, edge[i].v))
		{
			ans += edge[i].w;
			k++;
		}
	}
	return ans;
}

int main()
{
	int n;
	char from, to;
	int e, w;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n - 1; i++)
		{
			cin >> from >> e;
			for (int j = 0; j < e; j++)
			{
				cin >> to >> w;
				AddEdge(from - 'A' + 1, to - 'A' + 1, w);
				AddEdge(to - 'A' + 1, from - 'A' + 1, w);
			}
		}
		cout << Kruskal(n) << endl;
		ecnt = 0;
	}
	
	return 0;
}
