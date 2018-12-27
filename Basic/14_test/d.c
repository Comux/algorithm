#include <stdio.h>
typedef long long ll;
int a[100005];

// the work capacity of the machine
ll Capacity(int n, ll mid, int m)
{
	ll ans = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		ans += mid / a[i];
		if (ans > m) // have washed enough clothes
   			return ans;
	}
	return ans;
}

int main()
{
	int n, m, i;
	ll ans = 0;
	ll right, left, mid, now;
	
	scanf ("%d %d", &n, &m);
	
	for (i=0; i<n; i++)
	{
		scanf ("%d",&a[i]);
	}
	
	left = 0;
	right = 1e11; // 100000 * 1000000
	while (right >= left)
	{
		mid = (right + left) >> 1;
		ans = Capacity(n, mid, m);
		if (ans > m)
		{
			now = mid;
			right = mid - 1;
		}
		else if (ans < m)
		{
			left = mid + 1;
		}
		else// (ans==m)
		{	
			now = mid;
			break;	
		}
	}
	printf ("%lld", now);
	return 0;
}

/* test
3 6
1 2 3
=> 4
*/

/* 题解
对于每一个时间，每台洗衣机都可以求得在这段时间内可以洗涤的最大衣物，
因此，我们可以遍历所有的时间，找出刚好能够洗涤对应数量的时间点。
这个过程可以利用二分查找优化时间。本题潜在的条件是时间越多，洗得也越多。
这就符合二分查找有序的前提。时间复杂度: O(nlogn); 
*/
