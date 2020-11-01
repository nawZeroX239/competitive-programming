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

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int x[] = { 0, 0, 1, -1 };
int y[] = { -1, 1, 0, 0 };

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, k, s, t, u, v, f, g;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; ++i) {
		cin >> m;
		adj[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> adj[i][j];
		}
	}
	
	cin >> t;
	int dist[2500] = {}, day[2500] = {};

	while (t--) {
		cin >> s;
		if (adj[s].size() == 0) {
			cout << 0 << '\n';
			continue;
		}

		queue<int> q;
		q.push(s);
		for (int i = 0; i < n; ++i) dist[i] = day[i] = 0;
		dist[s] = 1;
		while (q.size()) {
			u = q.front(); q.pop();
			for (int i = 0; i < adj[u].size(); ++i) {
				v = adj[u][i];
				if (dist[v] == 0) {
					day[dist[u]]++;
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		f = -1, g = 0;
		for (int i = 1; i < n; ++i) {
			if (f < day[i]) {
				f = day[i];
				g = i;
			}
		}
		cout << f << ' ' << g << '\n';
	}
}

