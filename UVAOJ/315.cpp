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
int dfsLow[100], dfsNum[100], dfsParent[100], dfsCtr, n, child;
bool artPt[100];
void findArtPt(int u) {
	dfsLow[u] = dfsNum[u] = dfsCtr++;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (dfsNum[v] == INF) {
			if (u == 0) ++child;
			dfsParent[v] = u;
			findArtPt(v);
			if (dfsLow[v] >= dfsNum[u])
				artPt[u] = true;
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
	int u, v;
	while (getline(cin, s)) {
		if (s[0] == '0') break;
		n = toInt(s);
		adj.clear(); adj.resize(n);
		while (getline(cin, s)) {
			if (s[0] == '0') break;
			stringstream ss(s);
			ss >> u;
			while (ss >> v) {
				adj[u - 1].push_back(v - 1);
				adj[v - 1].push_back(u - 1);
			}
		}
		for(int i = 0; i < n; ++i) {
			dfsNum[i] = INF;
			artPt[i] = false;
			// cout << "adj[" << i << "].size() " << adj[i].size() << '\n';
		}
		child = dfsCtr = 0;
		findArtPt(0);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (artPt[i]) ++ans;
		}

		if (child < 2) ans--;
		cout << ans << '\n';
	}
	
}