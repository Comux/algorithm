#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define swap(a, b) do { int t = a; a = b; b = t; }  while (0)

const int V = 50005; /*, E = 200005*/
const int INF = 0x3f3f3f3f;

struct edge { int to, cost; };
typedef pair<int, int> P; // first => distance, second => vertex number
vector<edge> G[V];
int d[V];
priority_queue<P, vector<P>, greater<P> > Q;

void Dijkstra(int s)
{
	fill(d, d + V, INF);
	d[s] = 0;
	Q.push(P(0, s));
	
	int v;
	edge e;
	while (!Q.empty())
	{
		P p = Q.top(); Q.pop();
		v = p.second;
		if (d[v] < p.first) continue;

		for (int i = 0; i < G[v].size(); ++i) {
			e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				Q.push(P(d[e.to], e.to));
			}
		}
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int a;
	edge e;
	for (int i = 0; i < m; i++)
	{	
		scanf("%d %d %d", &a, &e.to, &e.cost);
		G[a].push_back(e);
		swap(a, e.to); // swap src and dest
		G[a].push_back(e);
	}
	
	Dijkstra(1);
	printf("%d", d[n]);

	return 0;
}
