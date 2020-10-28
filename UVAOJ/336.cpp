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
	
	int ans, nc, id, u, v, s, ttl, tc = 1;
	while (cin >> nc) {
		if (nc == 0) break;
		vector<pair<int, int>> edge(nc);
		unordered_map<int, int> mp;
		id = 0;
		for (int i = 0; i < nc; ++i) {
			cin >> edge[i].first >> edge[i].second;
			u = edge[i].first, v = edge[i].second;
			if (mp.find(u) == mp.end()) mp[u] = id++;
			if (mp.find(v) == mp.end()) mp[v] = id++;
		}
		vector<vector<int>> adj(id);
		for (int i = 0; i < nc; ++i) {
			u = mp[edge[i].first], v = mp[edge[i].second];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}


		vector<int> dist(id, INF);
		queue<int> q;

		while (cin >> s >> ttl) {
			if (s == 0 && ttl == 0) break;
			q.push(mp[s]);
			ans = dist[mp[s]] = 0;
			while (q.size() > 0) {
				u = q.front(); q.pop();
				for (int i = 0; i < adj[u].size(); ++i) {
					v = adj[u][i];
					if (dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
			for (int i = 0; i < id; ++i) {
				// cout << "debug: " << dist[mp[s]] << ' ' << dist[i] << ' ' << '\n';
				if (dist[i] > ttl || dist[i] == INF) ans++;
				dist[i] = INF;
			}
			cout << "Case " << tc++<<": " << ans << " nodes not reachable from node " << s << " with TTL = " << ttl << '.' << '\n';
		}
	}
	
}