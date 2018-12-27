#include <stdio.h>

#define N 14
int tree[N]; // 二叉树  
int vis[N];
int first[N]; // 第一次到达某一结点所经过的的路程
int cot = 0;

void Traverse(int src, int n)
{ 
	int p; 
	if (!vis[src])
		first[src] = cot++;
	vis[src] = 1;
	
	p = src<<1;
	if (p+1 <= n && tree[p] && tree[p+1]) // let left son > right son
	{
		if (tree[p] < tree[p+1])
		{
			Traverse(p+1, n);
			cot++;
			Traverse(p, n);
		}
		else
		{
			Traverse(p, n);
			cot++;
			Traverse(p+1, n);
		}
	}
	else if (p <= n && tree[p])
	{
		Traverse(p, n);
		cot++;
	}
	else if (p+1 <= n && tree[p+1])
	{
		Traverse(p+1, n);
		cot++;
	}
}

int main(void)
{
	int n, m, i, p, x, k;
	
	scanf("%d", &n);
	for ( i=1; i<n; i++ )
	{
		scanf("%d %d", &p, &x);
		p<<=1;
		if (tree[p] == 0) { // insert in left
			tree[p] = x;
		} else {
			tree[p+1] = x;
		}
	}
	
	Traverse(1, );
	
//	for ( i=1; i<n; i++ )
//		printf("%d ", first[i]);
	
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &k);
		printf("%d\n", first[k]);
	}

	return 0;
}

/* test
3
1 30
1 40
3
1 2 3
=>
0
3
1
-------------------
6
1 20
1 30
2 40
2 50
3 60
3
1 3 5
*/ 
