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
int tx[] = { 0, 0, 1,  1, 1, -1, -1, -1 };
int ty[] = {-1, 1, 0, -1, 1,  0, -1,  1 };
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
vector<int> ts;
bool vis[100];
void dfs2(int u) {
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!vis[v]) {
			dfs2(v);
		}
	}
	ts.push_back(u);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, u, v;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		adj.clear(); adj.resize(n);
		for (int i = 0; i < m; ++i) {
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
		}
		for (int i = 0; i < n; ++i) vis[i] = false;
		ts.clear();
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs2(i);
			}
		}

		for (int i = ts.size() - 1; i > 0; --i) {
			cout << ts[i]+1 << ' ';
		}
		cout << ts[0]+1<< '\n';
	}
}