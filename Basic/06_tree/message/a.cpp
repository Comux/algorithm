#include <cstdio>
#include <vector>
using namespace std;

const int N = 2 * 100000 + 5;
int node[N];
int index[N];
int num[N];
vector<int> tree[N];

inline int read()
{
	int data = 0;
	char ch = 0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') data = data*10+ch-'0', ch=getchar();
	return data;
}

int cnt = 0;
void DFS(int s)
{
	num[s] = 1; 
	node[++cnt] = s;
	index[s] = cnt; 
	int sz = tree[s].size();
	for (int i=0; i<sz; i++)
	{
		int to = tree[s][i];
		DFS(to);
		num[s] += num[to];
	}
}

int main(void)
{
	int n, m, fa;
	scanf("%d %d", &n, &m);
	
	for (int son = 2; son <= n; ++son)
	{
		fa = read();
		tree[fa].push_back(son);
	}
	
	DFS(1);

	int u, k;
	while (m--)
	{
		scanf("%d %d", &u, &k);
		if (k > num[u])
			printf("-1\n");
		else
			printf("%d\n", node[index[u] + k - 1]);
	}
	
	return 0;
}
