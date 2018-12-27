// 260ms, 6524kb
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Prefix
{
	string S;
	Prefix *left = NULL;
	Prefix *right = NULL;
};

void Judge(const Prefix *p, const string& a);
int c; // global counter used for recusive function

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, i;
	string a;
	Prefix *root, *p, *q;
	root = new Prefix;
	root->S = "\0";

	p = root;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		q = new Prefix;
		q->S = a;
		p = root;
		
		while (true)
		{
			if (strcmp(a.c_str(), p->S.c_str()) < 0)
			{
				if (p->left)
				{
					p = p->left;
				}
				else
				{
					p->left = q;
					break;	
				}
			}
			else // >=
			{
				if (p->right)
				{
					p = p->right;
				}
				else
				{
					p->right = q;
					break;	
				}
			}
		}
	}
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		c = 0;
		p = root->right;
		Judge(p, a);
		cout << c << endl;
	}
	
	return 0;
}

void Judge(const Prefix *p, const string& a)
{
	if (strncmp(a.c_str(), p->S.c_str(), a.size()) == 0)
	{
		c++;
	}
	if (strncmp(a.c_str(), p->S.c_str(), a.size()) >= 0 && p->right)
	{
		Judge(p->right, a);
	}
	else if (strncmp(a.c_str(), p->S.c_str(), a.size()) <= 0 && p->left)
	{
		Judge(p->left, a);
	}
}

/* ���
�������ǰ׺˼�룬ͬʱ���ö�����������˼�룬
�涨���������ֵ�����ڸ��ڵ㣬���������ֵ���С�ڸ��ڵ㣻
�㷨��ʼʱ�����Ƚ�����
ͨ������ڵ�Ƚϣ��ҵ���һ���Ƚϵĸ���ֱ���ø��ڵ��޶�Ӧ�������ɹ��Ƚϡ�

					 '/0'
			         /   \ 
			            babaab (root) 
                       /	  \
				  babbbaaaa   abba
			      /     \        \ 
				    babaababb    aaaaabaa

��ѯǰ׺��ʱ���Ӹ��ڵ㿪ʼ����3�������
	1. �ֵ��� > ���ڵ� => �ݹ�����������
	2. �ֵ��� < ���ڵ� => �ݹ�����������
	3. �ֵ��� = ���ڵ� => �ݹ�������������	
*/
