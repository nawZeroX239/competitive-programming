#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <bitset>
using namespace std;

#define N 100000
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

int h[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, u, v, ans;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; ++i) cin >> h[i];
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	
	ans = 0;
	for (int i = 0; i < n; ++i) {
		if (adj[i].size() == 0){
			++ans;
		} else {
			bool ok = true;
			for (int j = 0; j < adj[i].size(); ++j)
				ok = ok && h[i] > h[adj[i][j]];
			ans += ok;
		}
	}
	cout << ans << '\n';
}
