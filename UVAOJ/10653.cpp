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

	vector<vector<int>> adj;
	int n, m, r, c, k, f, dist[1000][1000];
	pair<int, int> u, v, s, d;
	bool g[1000][1000];
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			g[i][j] = 1;
			dist[i][j] = INF;
		}

		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> r >> f;
			for (int j = 0; j < f; ++j) {
				cin >> c;
				g[r][c] = 0;
			}
		}

		//for (int i = 0; i < n; ++i) {
		//	for (int j = 0; j < m; ++j) {
		//		if (i + 1 < n && !g[i + 1][j]) {
		//			u = n * i + j, v = n * (i + 1) + j;
		//			adj[u].push_back(v);
		//			adj[v].push_back(u);
		//		}
		//		if (j + 1 < m && !g[i][j + 1]) {
		//			u = n * i + j, v = n * i + j + 1;
		//			adj[u].push_back(v);
		//			adj[v].push_back(u);
		//		}
		//		dist[n * i + j] = INF;
		//	}
		//}

		cin >> s.first >> s.second >> d.first >> d.second;
		queue<pair<int, int>> q;
		q.push(s);
		dist[s.first][s.second] = 0;
		while (q.size()) {
			u = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				v.first = x[i] + u.first;
				v.second = y[i] + u.second;
				if (v.first >= 0 && v.first < n && v.second >= 0 && v.second <= m && g[v.first][v.second]
					&& dist[v.first][v.second] == INF) {
					dist[v.first][v.second] = dist[u.first][u.second] + 1;
					q.push(v);
					if (v == s) break;
				}
			}
		}
		cout << dist[d.first][d.second] << '\n';
	}

}

