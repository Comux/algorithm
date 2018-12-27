const int maxn = 1e5 + 10;

struct Edge
{
    int u, v, w;
    Edge(int _u = 0, int _v = 0, int _w = 0) { u = _u, v = _v, w = _w; }
};
vector<Edge> E;
vector<int> G[maxn];
void init(int l, int r)
{
    E.clear();
    for (int i = l; i <= r; i++)
        G[i].clear();
}
void addedge(int u, int v, int w)
{
    E.push_back(Edge(u, v, w));
    G[u].push_back(E.size() - 1);
}
