// 100ms, 16076kb
#include <stdio.h>

typedef struct node
{
	int ctr;
	char ch;
	int son;
	int nex;
} no;

#define N 50000+(30-4)*50000+26*2 // ??
#define M 26
#define D 97 //'a'

no mal[N];
int mp = 0;

int main(void)
{
	char s[39];
	int i, j, p, f, n, m;

	for( i=1; i<=M; i++ )
	{	
		mal[i].ctr = 0;
		mal[i].ch = D + i - 1;
		mal[i].son = 0;
		mal[i].nex = 0;
	}
	mp = M+1;

	scanf("%d", &n);
	for( i=0; i<n; i++ )
	{
		scanf("%s", s);
		f = s[0] - D + 1;
		mal[f].ctr++;
		p = mal[f].son;
		j = 1;
		while (s[j])
		{
			while(p && mal[p].ch != s[j])
				p = mal[p].nex;

			if (p) // find some common prefix
			{
				mal[p].ctr++;
				f = p;
				p = mal[p].son;
			}
			else // can't find
			{
				mal[mp].ctr = 1;
				mal[mp].ch = s[j];
				mal[mp].son = 0;
				mal[mp].nex = mal[f].son; // front insert to the son list
				mal[f].son = mp;
				f = mp;
				mp++; // memory allocated
				p = 0; // no common prefix, will always insert new node
			}
			
			j++;
		}
	}

	scanf("%d", &m);
	for( i=0; i<m; i++ )
	{
		scanf("%s", s);
		f = s[0] - D + 1;
		j = 1;
		p = mal[f].son;
		while(p && s[j])
		{
			while(p && mal[p].ch != s[j]) // search in the brother list
				p = mal[p].nex;
			if(p)
			{
				f = p;
				p = mal[p].son;
				j++;
			}
		}

		printf("%d\n", !s[j] ? mal[f].ctr : 0); // !s[j] => find the prefix
	}

	return 0;
}
