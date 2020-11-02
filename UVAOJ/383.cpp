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
	
	int T, tc = 1, m, n, p, sz, u, v;
	string s, t;
	cin >> T;

	cout << "SHIPPING ROUTES OUTPUT\n\n";
	while (T--) {
		cin >> m >> n >> p;
		unordered_map<string, int> ind;
		vector<vector<int>> adj(m);
		for (int i = 0; i < m; ++i) {
			cin >> s;
			ind[s] = i;
		}
		for (int i = 0; i < n; ++i) {
			cin >> s >> t;
			adj[ind[s]].push_back(ind[t]);
			adj[ind[t]].push_back(ind[s]);
		}

		cout << "DATA SET  " << tc++ << "\n\n";
		for (int i = 0; i < p; ++i) {
			cin >> sz >> s >> t;
			int dist[30] = {};
			queue<int> q;
			q.push(ind[s]);
			dist[ind[s]] = 1;
			while (q.size()) {
				u = q.front(); q.pop();
				for (int j = 0; j < adj[u].size(); ++j) {
					v = adj[u][j];
					if (dist[v] == 0) {
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}

			if (dist[ind[t]] == 0) {
				cout << "NO SHIPMENT POSSIBLE" << '\n';
			} else {
				cout << '$' << 100 * sz * (dist[ind[t]] - 1) << '\n';
			}
		}
		cout << '\n';
	}
	cout << "END OF OUTPUT" << '\n';
}

