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

/* 题解
本题采用前缀思想，同时利用二叉搜素树的思想，
规定右子树的字典序大于父节点，左子树的字典序小于父节点；
算法开始时，首先建树，
通过与根节点比较，找到下一步比较的根，直到该根节点无对应的子树可供比较。

					 '/0'
			         /   \ 
			            babaab (root) 
                       /	  \
				  babbbaaaa   abba
			      /     \        \ 
				    babaababb    aaaaabaa

查询前缀数时，从根节点开始，分3种情况：
	1. 字典序 > 根节点 => 递归搜素右子树
	2. 字典序 < 根节点 => 递归搜素左子树
	3. 字典序 = 根节点 => 递归搜素左右子树	
*/
