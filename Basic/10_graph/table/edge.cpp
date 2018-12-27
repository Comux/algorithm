#include <cstdio>
#include <cstring>
#include <iostream>

const int E = 200000 + 5;
const int V = 50000 + 5;
const int INF = 0x3f3f3f3f;

// 链式前向星
struct Edge {
    int to;
    int w;
    int next;
} edge[E];
int head[V];
int ecnt;

void Init()
{
    ecnt = 0;
    memset(head, -1, sizeof(head));
}

void AddEdge(int u, int v, int w)
{
    edge[ecnt].to = v;
    edge[ecnt].next = head[u];
    edge[ecnt].w = w;
    head[u] = ecnt++;
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    Init();

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        AddEdge(a, b, c);
        AddEdge(b, a, c);
    }

    printf("\nhead:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", head[i]);
    }
    printf("\nto:\n");
    for (int i = 0; i <= 2 * m - 1; i++)
    {
        printf("%3d ", edge[i].to);
    }
    printf("\nnext:\n");
    for (int i = 0; i <= 2 * m - 1; i++)
    {
        printf("%3d ", edge[i].next);
    }
    printf("\n");

    int from = 1;
    for (int i = head[from]; i != -1; i = edge[i].next)
    {
        printf("%d->", edge[i].to);
    }

    return 0;
}
