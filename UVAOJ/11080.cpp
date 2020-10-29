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

int s[200];
vector<vector<int>> adj;
int z, o;
bool recur(int u) {
	
	if (s[u]) ++o;
	else ++z;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (s[v] == INF) {
			s[v] = 1 - s[u];
			if (!recur(v)) return false;
		}else if(s[v] == s[u]){
			return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, v, e, f, t, one;
	cin >> T;
	while (T--) {
		cin >> v >> e;
		adj.clear();
		adj.resize(v);
		for (int i = 0; i < v; ++i) s[i] = INF;

		for (int i = 0; i < e; ++i) {
			cin >> f >> t;
			adj[f].push_back(t);
			adj[t].push_back(f);
		}

		bool ok = true;
		int ans = 0;
		for (int i = 0; i < v && ok; ++i) {
			if (s[i] == INF) {
				s[i] = 0;
				o = z = 0;
				ok = ok && recur(i);
				int q = min(o, z);
				ans += max(q, 1);
			}
		}

		if (ok) {
			cout << ans << '\n';
		} else {
			cout << "-1" << '\n';
		}
		
	}
}