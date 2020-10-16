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

int adj[50000], dp[50000];
bool vis[50000];

int dfs(int u) {
	vis[u] = true;
	int tot = 0;
	if (!vis[adj[u]]) {
		tot = dfs(adj[u]);
	}
	vis[u] = false;
	return dp[u] = 1 + tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, tc = 1, n, u, v;
	cin >> T;

	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> u >> v;
			adj[u - 1] = v - 1;
			vis[i] = false;
			dp[i] = -1;
		}

		int ans=0, best=-1;
		for (int i = 0; i < n; ++i) {
			int temp = -1;
			if (dp[i] == -1) temp = dfs(i);
			else temp = dp[i];
			if (temp > best) {
				ans = i + 1;
				best = temp;
			}
		}
		cout <<"Case "<<tc++<<": "<< ans << '\n';
	}
}