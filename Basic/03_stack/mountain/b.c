#include <stdio.h>

#define N 5000005
typedef long long ll;
int h[N], st[N];

//inline int read()
//{
//    int data = 0;
//    char ch = 0;
//    while (ch<'0' || ch>'9') ch = getchar();
//    while (ch>='0' && ch<='9') data = data*10 + ch-'0', ch=getchar();
//    return data;
//}

int main()
{
	int n, i, t;
	ll sum = 0;
	scanf("%d", &n);
	st[n-1] = n-1;

	fread(&h[0], sizeof(int), n, stdin);
	fwrite(&h[0], sizeof(int), n, stdout);
	
//	for (i=0; i<n; i++)
//		h[i] = read();
	
	for (i = n-2; i>=0; i--)
	{
		t = i;
		while (t != n-1 && h[i] > h[t+1])
		{
			t = st[t+1];
		}
			
		st[i] = t;
		sum += (ll)(t - i);
	}
	printf("%lld", sum);
	return 0;
}
