#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1001 + 10;
int par[MAXN];
struct Point
{
	int x, y;
	bool vis;
} p[MAXN];

int Dist(const Point& a, const Point& b)
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int Find(int x)
{
	if (par[x] == -1) return x;
	return par[x] = Find(par[x]);
}

void Union(int x, int y, int d)
{
	int px = Find(x), py = Find(y);
	if (px != py) {
		if (Dist(p[x], p[y]) <= d) {
			par[px] = py;
		}
	}
}

int main()
{
	int N, d;
	scanf("%d %d", &N, &d);
	d *= d;
	memset(par, -1, sizeof(par));
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].vis = false;
	}
	
	char op[2];
	int a, b;
	while (~scanf("%s", op))
	{
		if (op[0] == 'O')
		{
			scanf("%d", &a);
			p[a].vis = true;
			for (int i = 1; i <= N; i++) {
				if (p[i].vis && i != a)
					Union(i, a, d);
			}
		}
		else
		{
			scanf("%d %d", &a, &b);
			printf("%s\n", Find(a) == Find(b) ? "SUCCESS" : "FAIL");
		}
	}
	
	return 0;
}
