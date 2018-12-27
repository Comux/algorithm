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
} edge[E << 1]; //  无向图 
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
				AddEdge(from, to, w);
				AddEdge(to, from, w); // 无向图 
			}
		}
		cout << Kruskal(n) << endl;
		ecnt = 0;
	}
	
	return 0;
}



//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int E = 1000 + 1;
//
//int UFSet[51];
//int Find(int x)
//{
//	if (UFSet[x] == -1) return x;
//	return UFSet[x] = Find(UFSet[x]);
//}
//
//struct Edge
//{
//	int u, v, w;
//	bool operator < (const Edge& e) const
//	{
//		return this->w < e.w;
//	}
//} edge[E << 1];
//int ecnt = 0;
//
//void AddEdge(int u, int v, int w)
//{
//	ecnt++;
//	edge[ecnt].u = u;
//	edge[ecnt].v = v;
//	edge[ecnt].w = w;
//}
//
//int Kruskal(int n)
//{
//	memset(UFSet, -1, sizeof(UFSet));
//	sort(edge + 1, edge + ecnt + 1); // [1..ecnt]
//
//	int k, s, t;
//	int ans = 0;
//	for (int i = 1; i <= ecnt && k < n-1; i++)
//	{
//		s = Find(edge[i].u);
//		t = Find(edge[i].v);
//		if (s != t)
//		{
//			UFSet[s] = t; // Union
//			ans += edge[i].w;
//			k++;
//		}
//	}
//	return ans;
//}
//
//int main()
//{
//	int n, e;
//	int u, v, w;
//	while (cin >> n && n != 0)
//	{
//		cin >> e;
//		for (int i = 0; i < e; i++)
//		{
//			cin >> u >> v >> w;
//			AddEdge(u, v, w);
//			AddEdge(v, u, w);
//		}
//		cout << Kruskal(n) << endl;
//		ecnt = 0;
//	}
//
//	return 0;
//}
