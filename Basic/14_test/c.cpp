#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct node *np;
typedef struct node
{
	int w;
	int left;
	int right;
}no;

#define N 100005
np head[N];

int main()
{
	np root;
	int n, m, i;
	int f, w;
	np tmp;
	
	scanf("%d", &n);
	memset(head, 0, sizeof(head));
	
	for (i=2; i<=n; i++)
	{
		scanf("%d %d", &f, &w);
		
		if (head[f].left == 0)
		{
			head[f].left = i;
		} else if (head[head[f].left].w < w) {
			t = head[head[f].left].w;
			head[head[f].left].w = w;
			w = t;
		}
		else {
			head[f].right = i;
		}
	}
	
	scanf("%d", &m);
	
	return 0;
}
