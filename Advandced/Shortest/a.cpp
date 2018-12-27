#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1000 + 1;

struct Cmp
{
	bool operator() < (int a, int b)
	{
		return dis[a] > dis[b];
	}
}

unordered_map<int, int> edge[N];
int dis[N];
bool vis[N];
priority_queue<int, vector<int>, Cmp> Q;

void Dijkstra(int src)
{
	memset(vis, false, sizeof(vis));
	fill(dis, dis + N, INF);
	Q.clear();
	Q.push(src);
	
	int u, v, w;
	while (!Q.empty())
	{
		u = Q.top();
		Q.pop();
		
		if (!vis[u])
		{
			vis[u] = true;
			for (auto it = edge[u].begin(); it != edge[u].end(); ++it)
			{
				v = it->first;
				w = it->second;
				if (dis[v] > dis[v] + w)
				{
					dis[v] = dis[u] + w;
					Q.push(v);
				}
			}
		}
	}
}

int main()
{
	int t, s, d;
	int u, v, w;
	while (scanf("%d %d %d", &t, &s, &d) != EOF)
	{
		for (int i = 0; i <= N; i++)
			edge[i].clear();
		while (t--)
		{
			scanf("%d %d %d", &u, &v, &w);
			if (edge[u][v]) {
				edge[u][v] = edge[v][u] = min(edge[u][v], w);
			} else {
				edge[u][v] = edge[v][u] = w;
			}
		}
		
		int ans = INF;
		for (int i = 0; i < s; i++)
		{
			Dijkstra(i);
			for (int i = 1; i <= d; i++)
			{
				ans = min(ans,
			}
		}
	}
	
	return 0;
}
