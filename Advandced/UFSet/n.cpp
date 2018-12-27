#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int Find(map<int, int>& mp, int x)
{
	int r = x;
	while (mp.find(r) != mp.end() && mp[r] != x)
		r = mp[r];
	return r;
}

bool IsTree(map<int, int>& mp)
{
	int r = Find(mp, mp.begin()->first);
	int s;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		s = Find(mp, it->first);
		if (s != r || s == -1)
			return false;
	}
	return true;
}

int main()
{
	int a, b, cnt = 0;
	map<int, int> mp;
	while (cin >> a >> b && a != -1)
	{
		if (a == 0 && b == 0) {
			cout << "Case " << ++cnt << " is " << (IsTree(mp) ? "" : " not ") << "a tree.\n";
			mp.clear();
		}
		else {
			if (mp.find(b) != m.end() || a == b)
				mp[b] = -1;
			else
				mp[b] = a;
		}
	}
	
	return 0;
}
