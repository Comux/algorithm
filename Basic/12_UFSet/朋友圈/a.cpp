#include <cstdio>
//#include <queue>

const int N = 100005;
int par[N];
int cnt[N];

//#define DEBUG

int Find(int x)
{
    if (par[x] == -1) return x; 
    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    int u = Find(x);
    int v = Find(y);
	
	if (u == v) return ; // important
	
	par[u] = v;
	cnt[v] += cnt[u];
	cnt[u] = 0;
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        cnt[i] = 1;
    }

    int x, y;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        Union(x, y);
    }

    //std::make_heap(cnt + 1, cnt + n + 1);
	int max = cnt[0];
	for (int i = 2; i <= n; ++i)
		if (cnt[i] > max) max = cnt[i];

    printf("%d", max);
    return 0;
}

/*
int Find(int x)
{
	int root = x, t;
	
	while (par[root] != -1)
	{
		root = par[root];
	}
	
	while (x != root)
	{
		t = par[x];
		par[x] = root;
		x = t;
	}

	return root;
}*/


/*
#ifdef DEBUG	
	for (int i = 1; i<=n;i++)
		printf("%d %d\n", par[i], cnt[i]);
	
	printf("Debuging...\n");
#endif
*/