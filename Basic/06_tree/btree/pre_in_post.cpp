#include <cstdio>

const int N = 10000 + 5;
int pre[N], in[N];
int mapIndex[N];

void PostOrder(int root, int begin, int end)
{
	if (begin > end) return ; // End the recursion
	int rootVal = pre[root];
	int mid = mapIndex[rootVal];
	
	PostOrder(root+1, begin, mid-1); // left-child
	PostOrder(root+1+mid-begin, mid+1, end); // right-child
	printf("%d ", rootVal); // root
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		mapIndex[in[i]] = i;
	}
	
	PostOrder(0, 0, n-1);
	return 0;
}

/*
8
1 4 3 2 5 6 7 8
4 3 1 6 5 8 7 2

3 4 6 8 7 5 2 1
*/
