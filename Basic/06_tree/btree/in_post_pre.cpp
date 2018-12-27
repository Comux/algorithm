#include <cstdio>

#define rep(i, b, e) for(i=b; i<=e; i++)

const int N = 10000 + 5;
int mapIndex[N]; // map for getting one element from inorder in O(1)
int in[N];
int post[N];

void PreOrder(int root, int front, int end)
{
	if (front > end) return ;
	int rootVal = post[root];
	int mid = mapIndex[rootVal];
	
	printf("%d ", rootVal); // root
	PreOrder(root-1-end+mid, front, mid-1); // left-child
	PreOrder(root-1, mid+1, end); // right-child
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	
	rep(i, 1, n) {
		scanf("%d", &in[i]); // inorder
		mapIndex[in[i]] = i;
	}
	rep(i, 1, n) {
		scanf("%d", &post[i]); // postorder
//		printf("%d ", mapIndex[post[i]]); // 1 4 3 2 5 6 7 8
	} 
	
	PreOrder(n, 1, n);
	return 0;
}

/*
8
4 3 1 6 5 8 7 2
3 4 6 8 7 5 2 1

1 4 3 2 5 6 7 8
*/

