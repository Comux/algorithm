#include <cstdio>
#include <cstring>
#include <queue>

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int V = 50000 + 5; // max vertex number
const int E = 200000 + 5;// max edge number

// Chain-forward-star
int n, m, ecnt = 0, head[V] = { 0 };
struct node
{
    int v;
    int next;
    int w;
} edge[E * 2];

void AddEdge(int u, int v, int w)
{
    edge[++ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}

std::priority_queue<std::pair<ll, int> > Q;
ll dis[V];
bool vis[V] = { false };

void Dijkstra()
{
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    Q.push(std::make_pair(0, 1)); // weight + number

    while (!Q.empty())
    {
        int u = Q.top().second; // from V-S pick the vertex with the min distance
        Q.pop();
        if (vis[u]) continue;
        vis[u] = true; // add to S
        for (int i = head[u]; i; i = edge[i].next)
        { // enumerate the edges linked to u
            int v = edge[i].v, w = edge[i].w;
            if (dis[v] > dis[u] + w)
            {                                  // search for edge which can loose
                dis[v] = dis[u] + w;           // update distance
                Q.push(std::make_pair(-dis[v], v));
            }
        }
    }
    return ;
}

int main()
{
    scanf("%d %d", &n, &m);
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        AddEdge(a, b, c);
        AddEdge(b, a, c);
    }

    Dijkstra();
    printf("%d", dis[n]);

    return 0;
}
