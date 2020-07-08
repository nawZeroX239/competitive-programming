#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define N 20
#define A 23
using namespace std;

char ch[N][N];
bool vis[N][N], sol;
int n;

set<string> ans[A];

void dfs(int i, int j, string s) {
	if(s.length()>=3) ans[s.length() - 3].insert(s);
	if (i<0 || j<0 || i>=n || j>=n || vis[i][j])
		return;
	if (s.length() && s[s.length() - 1] >= ch[i][j]) 
		return;
	s = s + ch[i][j];
	vis[i][j] = true;

	dfs(i - 1, j, s);
	dfs(i + 1, j, s);
	dfs(i, j + 1, s);
	dfs(i, j - 1, s);

	dfs(i + 1, j + 1, s);
	dfs(i + 1, j - 1, s);
	dfs(i - 1, j - 1, s);
	dfs(i - 1, j + 1, s);
	vis[i][j] = false;
}

int main() {
	int tc;
	string ins;
	cin >> tc;
	while (tc) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> ins;
			for (int j = 0; j < n; ++j)
				ch[i][j] = ins[j];
		}
		for(int i=0; i<n; ++i)
			for (int j = 0; j < n; ++j) {
				dfs(i, j, "");
			}
		for (int i = 0; i < A; ++i) {
			for (auto it = ans[i].begin(); it != ans[i].end(); ++it)
				cout << *it << '\n';
			ans[i].clear();
		}

		--tc;
		if (tc) cout << '\n';
	}
}