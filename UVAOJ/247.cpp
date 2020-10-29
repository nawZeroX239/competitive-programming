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

string names[25];
vector<vector<int>> adj;
vector<int> S;
int dfsLow[25], dfsNum[25], dfsNumCounter;
bool vis[25];
void tarjanSCC(int u) {

	dfsNum[u] = dfsLow[u] = dfsNumCounter++;
	S.push_back(u);
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (dfsNum[v] == INF) {
			tarjanSCC(v);
		}
		if (vis[v]) {
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		}
	}

	if (dfsNum[u] == dfsLow[u]) {
		while (1) {
			int v = S.back(); S.pop_back();
			cout << names[v];
			vis[v] = 0;
			if (u == v) break;
			cout <<", ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, tc = 1;
	string s, t;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		unordered_map<string, int> mp;
		int pos = 0;
		adj.clear(); adj.resize(n); dfsNumCounter = 0;
		for (int i = 0; i < n; ++i) dfsNum[i] = INF;
		for (int i = 0; i < m; ++i) {
			cin >> s >> t;
			if (mp.find(s) == mp.end()) {
				mp[s] = pos;
				names[pos++] = s;
			}

			if (mp.find(t) == mp.end()) {
				mp[t] = pos;
				names[pos++] = t;
			}

			adj[mp[s]].push_back(mp[t]);
		}
		if (tc > 1) cout << '\n';
		cout << "Calling circles for data set " << tc++ << ':' << '\n';
		for (int i = 0; i < n; ++i) {
			// cout <<"dfsNum: "<<dfsNum[i] << '\n';
			if(dfsNum[i] == INF) tarjanSCC(i);
		}
		
	}

}