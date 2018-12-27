#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 10000 + 5;
vector<int> G[N]; // graph
priority_queue<int, vector<int>, greater<int> > Q;
int in[N] = { 0 }; // indegree

void TopoSort(int n)
{
	int v;
	for (v = 1; v <= n; v++)
	{
		if (in[v] == 0)
			Q.push(v);
	}
	
	while (!Q.empty())
	{
		v = Q.top();
		Q.pop();
		cout << v << " ";
		for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); ++it)
		{
			if (--in[*it] == 0)
				Q.push(*it);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, t;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
        {
        	cin >> t;
        	Q.push(t);
			in[t]++;
		}
		while (!Q.empty())
		{
			t = Q.top();
			Q.pop();
			G[i + 1].push_back(t);
		}
	}
	
	TopoSort(n);

	return 0;
}
