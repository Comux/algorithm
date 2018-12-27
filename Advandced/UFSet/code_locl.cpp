#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;

const int MAXN = int(1e7 + 10);
const int MUL = 26;
const int MOD = int(1e9 + 7);

int par[MAXN];
int Find(int x)
{
	if (par[x] == -1) return x;
	return par[x] = Find(par[x]);
}

bool Union(int lhs, int rhs)
{
	int pl = Find(lhs), pr = Find(rhs);
	if (pl == pr) return false;
	par[pl] = pr;
	Find(lhs); // reset the par[L, R] to R + 1
	return true;
}

int Pow(int n) // 二分快速幂求 26^n
{
	LL mul = MUL;
	LL ans = 1;
	while (n > 0)
	{
		if (n & 1) // odd (A=a*A*A)
		{
			ans *= mul;
			ans %= MOD;
		}
		n >>= 1;
		mul *= mul;
		mul %= MOD;
	}
	return int(ans);
}

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(par, -1, sizeof(par));
		int cnt = 0;
		for (int i = 0; i < M; ++i)
		{
			int L, R;
			scanf("%d %d", &L, &R);
			if (Union(L, R+1)) // par[L] = R + 1
				cnt++;
		}
		printf("%d\n", Pow(N - cnt));
	}
	
	return 0;
}
