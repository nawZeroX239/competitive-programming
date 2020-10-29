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
vector<pair<int, int>> ans;
int dfsLow[100], dfsNum[100], dfsParent[100], dfsCount;
bool artPt[100];
void findArtPt(int u) {
	dfsLow[u] = dfsNum[u] = dfsCount++;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (dfsNum[v] == INF) {
			dfsParent[v] = u;
			findArtPt(v);
			if (dfsLow[v] > dfsNum[u]) {
				ans.emplace_back(min(u, v), max(u, v));
			}
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else if (dfsParent[u] != v) {
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	int u, v, m, n, k, x;
	while (cin >> n) {
		adj.clear();  adj.resize(n);
		k = n;
		while(k--) {
			cin >> u >> s;
			x = m = 0;
			for (int i = s.length() - 2; i > 0; --i) {
				m += (s[i] - '0') * (int)pow(10, x++);
			}
			for (int i = 0; i < m; ++i) {
				cin >> v;
				adj[u].push_back(v);
			}
		}
		for (int i = 0; i < n; ++i) dfsNum[i] = INF;
		ans.clear();
		for (int i = 0; i < n; ++i) {
			if (dfsNum[i] == INF) {
				dfsCount = 0;
				findArtPt(i);
			}
		}

		cout << ans.size()<<" critical links" << '\n';
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i].first<<" - "<< ans[i].second << '\n';
		}
		cout << '\n';
	}
}