// 200ms, 29648kb
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 500005

typedef struct Node
{
	int cnt;
	char ch;
	struct Node *head;
	struct Node *next;
} no, *np;

np FindChar(const np sons, int ch) // find char in one level
{
	np p = sons->head;
	while (p && p->ch != ch)
		p = p->next;
	return p;
}

np NewNode(char ch)
{
	np p = (np)malloc(sizeof(no));
	p->cnt = 0;
	p->ch = ch;
	p->head = p->next = 0;
	return p;
}

void Insert(np root, const char* word)
{
	np p = root, q;
	while (*word)
	{
		if ((q = FindChar(p, *word)) == NULL) {
			q = NewNode(*word);
			q->next = p->head;
			p->head = q;
		}
		p = q;
		++p->cnt;
		++word;
	}
}

int Search(const np root, const char* word)
{
	np p = root;
	while (*word && p) {
		p = FindChar(p, *word);
		++word;
	}
	return (!p ? 0 : p->cnt);
}

int main()
{
	int n, i;
	np root = NewNode('\0');

	scanf("%d", &n);
	
	char word[31];
	for (i = 0; i < n; i++) {
		scanf("%s", word);
		Insert(root, word);
	}
	
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", word);
		printf("%d\n", Search(root, word));
	}
	
	// free root
	return 0;
}
