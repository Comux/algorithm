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

/* ���
����ÿһ��ʱ�䣬ÿ̨ϴ�»���������������ʱ���ڿ���ϴ�ӵ�������
��ˣ����ǿ��Ա������е�ʱ�䣬�ҳ��պ��ܹ�ϴ�Ӷ�Ӧ������ʱ��㡣
������̿������ö��ֲ����Ż�ʱ�䡣����Ǳ�ڵ�������ʱ��Խ�࣬ϴ��ҲԽ�ࡣ
��ͷ��϶��ֲ��������ǰ�ᡣʱ�临�Ӷ�: O(nlogn); 
*/
