#include <cstdio>
#include <vector>
using std::vector;

const int N = 200005;
vector<int> tree[N];
int index[N];
int node[N];
int end[N];
int cot; // counter

void Preorder(int cur)
{
	cot++;
	index[cur] = cot;
	node[cot] = cur;
		 
	for (int son = 0; son < tree[cur].size(); son++) // traverse the son node
	{
		Preorder(tree[cur][son]);
	}
	
	end[cur] = cot;
}

int main()
{
	int n, q, t;
	int u, k;
	int i;
	
	scanf("%d %d", &n, &q);	
	for (i = 2; i <= n; ++i)
	{
		scanf("%d", &t);
		tree[t].push_back(i);
	}
		
	cot = 0;
	node[1] = 1;
	index[1] = 1;
	Preorder(1);
	
	while (q--)
	{
		scanf("%d %d", &u, &k);
		if (k > end[u] - index[u] + 1) {
			printf("-1\n");
		} else {
			printf("%d\n", node[index[u] + k - 1]);
		}
	}
	
	return 0;
}


/*
test:

9 6
1 1 1 3 5 3 5 7
3 1
1 5
3 4
7 3
1 8
1 9

3 6 8 -1 9 4

debug:

	for (i = 1; i <= n; i++)
		printf("%d %d %d %d\n", i, node[i], index[i], end[i]); 
	printf("==--=-=-=-=-=-=-=-=\n"); 
*/

