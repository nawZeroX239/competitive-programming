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
bool  vis[102], reachable[102], g[102][102];

void dfs(int i) {
	reachable[i] = true;
	for (int j = 0; j < adj[i].size(); ++j) {
		if (!reachable[adj[i][j]]) dfs(adj[i][j]);
	}
}

void dfs2(int i, int k) {
	if (i == k) return;
	vis[i] = true;
	for (int j = 0; j < adj[i].size(); ++j) {
		if (!vis[adj[i][j]]) dfs2(adj[i][j], k);
	}
}
void plus_minus(int n) {
	cout << '+';
	for (int i = 0; i < 2 * n - 1; ++i) {
		cout << '-';
	}
	cout << '+'<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n, e;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		adj.resize(n);
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			for (int j = 0; j < n; ++j) {
				cin >> e;
				if (e == 1) {
					adj[i].push_back(j);
				}
			}
		}
		memset(g, 0, sizeof g);
		memset(reachable, 0, sizeof reachable);
		dfs(0);
		for (int i = 0; i < n; ++i) {
			if (reachable[i]) {
				g[i][i] = true;
				memset(vis, 0, sizeof vis);
				dfs2(0, i);
				for (int j = 0; j < n; ++j) {
					if (reachable[j] && !vis[j]) {
						g[i][j] = true;
					}
				}
			}
		}
		cout << "Case " << tc << ":" << '\n';
		plus_minus(n);
		for (int i = 0; i < n; ++i) {
			cout << '|';
			for (int j = 0; j < n; ++j) {
				cout << (g[i][j] ? 'Y': 'N') <<'|';
			}
			cout << '\n';
			plus_minus(n);
		}
	}
}