#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000 + 5;
int fa[N];
int son_cnt[N];

int main()
{
	int n;
	scanf("%d", &n);
	fa[1] = 0;
	int maxFa = 1;
	
	memset(son_cnt, 0, sizeof(son_cnt));
	for (int i = 2; i <= n; i++) {
		scanf("%d", &fa[i]);
		son_cnt[fa[i]]++;
		if (maxFa < fa[i])
			maxFa = fa[i];
	}
	
	bool ans = true;
	for (int i = maxFa; i > 0; --i)
	{
		if (son_cnt[i] == 0) continue;
		if (son_cnt[i] > 0 && son_cnt[i] < 3)
		{
			printf("No");
			ans = false;
			break;
		}
		son_cnt[fa[i]]--;
	}
	if (ans)
	{
		printf("Yes");
	}
	
	return 0;
}
