#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define INF 999999999
#define  EPS 1e-9
#define N  10000

// translation
int x[] = { 0, 0, 1, -1 };
int y[] = { -1, 1, 0, 0 };
using namespace std;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int toInt(string& s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}
vector<vector<int>> adj;
vector<int> S;
bool vis[100000];
void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		if (!vis[adj[u][i]]) dfs(adj[u][i]);
	}
	S.push_back(u);
}

void dfs2(int u) {
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		if (!vis[adj[u][i]]) dfs(adj[u][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc, n, m, u, v, ans;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		adj.clear();  adj.resize(n);
		for (int i = 0; i < m; ++i) {
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
		}
		for (int i = 0; i < n; ++i) vis[i] = 0;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) dfs(i);
		}
		for (int i = 0; i < n; ++i) vis[i] = 0;
		ans = 0;
		while (S.size()) {
			int u = S.back(); S.pop_back();
			if (!vis[u]) {
				++ans;
				dfs2(u);
			}
		}
		cout << ans << '\n';
	}
}