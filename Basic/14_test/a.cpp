#include <cstdio>
#include <list>
using namespace std;

int main()
{
	int n, m, t;
	scanf("%d %d", &n, &m);
	
	list<int> arr;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		arr.push_back(t);
	}
	
	arr.sort();
	
	list<int>::iterator it;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t);
		it = arr.begin();
		while (--t) ++it;
		arr.erase(it);
	}
	
	for (it = arr.begin(); it != arr.end(); ++it)
		printf("%d ", *it);

	return 0;
}
