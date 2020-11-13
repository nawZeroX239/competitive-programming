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

#define INF 1e9
#define  EPS 1e-9
#define N 20000
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int tx[] = { 0, 0, 1, -1 };
int ty[] = { -1, 1, 0, 0 };

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
int path[300];

void process(string &s) {
	int u, v;
	int pos=s.find('-');
	u = 0;
	for (int i = 0; i <pos; ++i) {
		u += (s[i] - '0') * pow(10, pos - i - 1);
	}
	--u;
	for (int i = pos + 1; i < s.length();) {
		pos = i, v = 0;
		while (pos < s.length() && s[pos] != ',') ++pos;
		for (int j = i; j < pos; ++j) {
			v += (s[j] - '0') * pow(10, pos - j - 1 );
		}
		--v;
		// cout <<u<<' '<< v << '\n';
		adj[u].push_back(v);
		// adj[v].push_back(u);
		i = pos+1;
	}
}


void printPath(int i) {
	if (i != -1) {
		printPath(path[i]);
		cout <<i+1<<' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, u, v, f, g;
	string s;
	while (cin>>n) {
		adj.clear(), adj.resize(n);
		
		
		for (int i = 0; i < n; ++i) {
			cin >> s;
			process(s);
		}
		cin >> m;
		cout << "-----\n";
		for (int i = 0; i < m; ++i) {
			cin >> u >> v; --u, --v;
			int dist[300] = {};
			// cout << u + 1 << ' ' << v + 1 << '\n';
			// memset(path, -1, sizeof path);
			queue<int> q;
			q.push(u);
			dist[u] = 1, path[u] = -1;
			while (q.size()) {
				f = q.front(); q.pop();
				if (f == v) break;
				for (int k = 0; k < adj[f].size(); ++k) {
					g = adj[f][k];
					if (dist[g] == 0) {
						dist[g] = dist[f] + 1;
						path[g] = f;
						q.push(g);
					}
				}
			}

			if (dist[v]) {
				printPath(path[v]);
				cout << v + 1 << '\n';
			} else {
				cout << "connection impossible" << '\n';
			}

		}
	}
}