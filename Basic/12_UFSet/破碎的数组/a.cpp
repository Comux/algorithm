#include <cstdio>
#include <stack>
using std::stack;

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef long long ll;
const int maxn = 100000 + 5;
int fa[maxn] = { 0 };
ll sum[maxn] = { 0 };
int del[maxn] = { 0 };
bool vis[maxn] = { false };
ll ans = 0;

int Find(int x)
{
    if (fa[x] == 0) return x;
    return fa[x] = Find(fa[x]);
}

void Union(int x, int y)
{
    int u, v;
    u = Find(x);
    v = Find(y);
	
	if (u == v) return ;
	
	fa[u] = v;
	sum[v] += sum[u];
	sum[u] = 0;
}

void Solve(int n)
{
	ll ans = 0;
    int cur;
	stack<ll> st;
	st.push(0);
	
    for (int i = n; i > 1; i--)
    {
        cur = del[i];
        vis[cur] = true;
        if (cur == n && vis[n - 1])
        {
           Union(n - 1, n);
        }
        else
        {
            if (vis[cur - 1])
                Union(cur - 1, cur);
            if (vis[cur + 1])
                Union(cur, cur + 1);
        }
        
		ans = max(ans, sum[Find(cur)]);
        st.push(ans);
    }

	while (!st.empty())
	{
		printf("%lld\n", st.top());
		st.pop();
	}
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &sum[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &del[i]);

    Solve(n);
    return 0;
}
