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
#include <sstream>
#include <set>
#include <map>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define N 256
using namespace std;
bool vis[N];
vector<vector<int>> adj;
vector<int> paths;
int n;


bool dfs(int k, int m) {
	if (m > n) return false;
	vis[k] = true;
	paths.push_back(k);
	for (int i = 0; i < adj[k].size(); ++i) {
		int j = adj[k][i];
		if (!vis[j] || m+1 == n && j == 0) {
			if (m + 1 == n && j == 0) {
				for (int i = 0; i <= m; ++i)
					cout << paths[i] + 1 << ' ';
				cout << 1 << '\n';
				return true;
			}
			if (dfs(j, m + 1)) return true;
		}

	}

	paths.pop_back();
	vis[k] = false;
	return false;
}


int main() {
	string s;
	int a, b;
	while (cin >> n) {
		getline(cin, s);
		paths.clear();
		adj.clear();
		adj.resize(n);
		while (getline(cin, s)) {
			if (s[0] == '%') break;
			stringstream ss(s);
			ss >> a >> b;
			adj[a - 1].push_back(b - 1);
			adj[b - 1].push_back(a - 1);
		}
		memset(vis, 0, sizeof vis);
		if (!dfs(0, 0)) {
			cout << "N"<< endl;
		}
	}
}