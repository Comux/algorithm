#include <stdio.h>
#include <stdlib.h>

#define N 200005

// treeNode
typedef struct node
{
	int num;
	struct node* next;
}no, *np; 
np head[N];
np tail[N];

// stack
int top;
int cot; // counter
struct
{
	int cur;
	np curp;
}stack[N];

int index[N];
int node[N];
int end[N];

int main()
{
	int n, q, t;
	scanf("%d %d", &n, &q);
	np ptr;
	int i;
	for (i = 1; i <= n; i++)
		head[i] = NULL;
	
	for (i = 2; i <= n; ++i)
	{
		scanf("%d", &t);
		
		// insert
		ptr = (np)malloc(sizeof(no));
		ptr->num = i;
		ptr->next = NULL;
		if (head[t])
		{
			tail[t]->next = ptr;
			tail[t] = tail[t]->next;
		} else {
			head[t] = tail[t] = ptr;
		}
	}
	
	top = 1;
	cot = 1;
	index[1] = 1;
	node[1] = 1;
	stack[top].cur = 1;
	stack[top].curp = head[1];
	while (top > 0)
	{
		ptr = stack[top].curp;
		if (stack[top].curp)
		{
			stack[top].curp = ptr->next;
			top++;
			stack[top].cur = ptr->num;
			stack[top].curp = head[stack[top].cur];
			index[ptr->num] = ++cot;
			node[cot] = ptr->num;
		} else {
			end[stack[top].cur] = cot;
			top--;
		}
	}
	
	for (i = 1; i <= n; i++)
		printf("%d %d %d %d\n", i, node[i], index[i], end[i]); 
	
	printf("==--=-=-=-=-=-=-=-=\n");
	
	int u, k;
	while (q--)
	{
		scanf("%d %d", &u, &k);
		if (end[u] - index[u] < k - 1)
		{
			printf("-1\n");
		} else {
			printf("%d\n", node[index[u] + k - 1]);
		}
	}
	
	return 0;
}
