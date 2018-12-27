#include <cstdio>
using namespace std;

#define lson k<<1
#define rson k<<1|1
const int N = 100000;
struct node
{
	int l, r, w, f; // w=>sum, f=>flag
} tree[N << 2 + 1]; // *4+1

inline void Update(int k)
{
	tree[k].w = tree[lson].w + tree[rson].w;
}

int ans, x, y, a, b; // range query

void Build(int k, int ll, int rr) // build the tree
{
	tree[k].l = ll, tree[k].r = rr;
	if (tree[k].l == tree[k].r)
	{
		scanf("%d", &tree[k].w);
		printf("\ntree[%d] = %d\n", k, tree[k].w);
		return ;
	}
	
	int mid = ( ll + rr ) / 2;
	Build( lson, ll, mid );
	Build( rson, mid+1, rr );
	
	Update(k);
}

void Down(int k) // push down the flag
{
	tree[lson].f += tree[k].f;
	tree[rson].f += tree[k].f;
	tree[lson].w = tree[k].f * (tree[lson].r - tree[lson].l + 1);
	tree[rson].w = tree[k].f * (tree[rson].r - tree[rson].l + 1);
	tree[k].f = 0;
}

int AskPoint(int k) // query xth num
{
	if ( tree[k].l == tree[k].r )
	{
		return tree[k].w;
	}
	if ( tree[k].f ) Down(k);
	int mid = (tree[k].l + tree[k].r) / 2;
	if ( x <= mid ) AskPoint( lson );
	else            AskPoint( rson );
}

void ChangePoint(int k) // add y
{
    if ( tree[k].l == tree[k].r )
    {
    	tree[k].w += y;
		return ;
	}
	if ( tree[k].f ) Down(k);
	int mid = ( tree[k].l + tree[k].r ) / 2;
	if ( x <= mid ) ChangePoint( lson );
	else            ChangePoint( rson );
	
	Update(k);
}

void AskInterval(int k)
{
	if ( a <= tree[k].l && tree[k].r <= b )
	{
		ans += tree[k].w;
		return ;
	}
	if ( tree[k].f ) Down(k);
	int mid = ( tree[k].l + tree[k].r ) / 2;
	if ( a <= mid ) AskInterval( lson );
	if ( b > mid )  AskInterval( rson );
}

void ChangeInterval(int k)
{
	if ( a <= tree[k].l && tree[k].r <= b )
	{
		tree[k].w += ( tree[k].r - tree[k].l + 1 ) * y;
		tree[k].f += y;
		return ;
	}
	if ( tree[k].f ) Down(k);
	int mid = ( tree[k].l + tree[k].r ) / 2;
	if ( a <= mid ) ChangeInterval( lson );
	if ( b > mid )  ChangeInterval( rson );
	Update(k);
}

int main(void)
{
	int n, m, p, i;
	scanf("%d", &n);
	Build(1, 1, n);
	for ( i=1; i<=n; i++ )
		{
			printf("%d ", tree[i].w);
		}
		puts("");
	
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &p);
		if ( p == 1 ) { // 单点查询
			scanf("%d", &x);
			AskPoint( 1 );
            printf("%d\n", tree[1].w);
		} else if ( p == 2 ) { // 单点修改
			scanf("%d %d", &x, &y);
			ChangePoint( 1 );
			printf("%d\n", tree[1].w);
		} else if ( p == 3 ) { //
			scanf("%d %d", &a, &b);
			AskInterval( 1 );
			printf("%d\n", ans);
		} else if ( p == 4 ) {
			scanf("%d %d %d", &a, &b, &y);
			ChangeInterval( 1 );
		} else {
			;
		}
		
		for ( i=1; i<=4*n; i++ )
		{
			printf("%d ", tree[i].w);
		}
		puts("");
	}

	getchar();
	return 0;
}

/*
	10
	1 2 3 4 5 6 7 8 9 10
	4
	1 3
	2 3 4
	3 1 5
	4 1 5 2
*/
