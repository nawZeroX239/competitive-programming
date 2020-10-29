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
int s[200];
bool recur(int u) {
	bool flag = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (s[v] == INF) {
			s[v] = 1 - s[u];
			flag = flag && recur(v);
			if (!flag) return flag;
		}else if (s[u] == s[v]) {
			return false;
		}
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, u, v, l;
	while (cin >> n) {
		if (n == 0) break;
		cin >> l;
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < l; ++i) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i < n; ++i) {
			s[i] = INF;
		}
		s[0] = 0;
		if (recur(0)) {
			cout << "BICOLORABLE." << '\n';
		} else {
			cout << "NOT BICOLORABLE." << '\n';
		}
	}
}