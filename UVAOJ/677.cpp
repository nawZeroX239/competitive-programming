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
#include <numeric>
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

#define EPS 1e-9
#define N 10
#define PIXEL 1024
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline void newline() { cout << '\n'; }
inline void split(vector<string>& vect, string& str, char delim) {
	string each;
	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it != delim)
			each.push_back(*it);
		else {
			vect.push_back(each);
			each.clear();
		}
	}
	if (each.size()) vect.push_back(each);
}

inline bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.first < right.first;
}

inline bool lb_pred(const pair<int, int>& left, int right) {
	return left.first < right;
}

// int P[N], Q[N];

vector<vector<int>> adj;
bool visited[N][N];
int len, n;
vector<int> paths;
bool sol;

bool can_go(int k) {
	if (k == 0) return false;
	for (auto x : paths)
		if (x == k) return false;
	return true;
}

void dfs(int i) {
	if (paths.size() == len) {
		cout << "(1";
		for (auto it = paths.begin(); it != paths.end(); ++it)
			cout << ',' << *it + 1;
		cout << ")\n";
		sol = true;
		return;
	}

	for (int j = 0; j < adj[i].size(); ++j) {
		int k = adj[i][j];
		if (visited[i][k] == false && can_go(k)) {
			visited[i][k] = visited[k][i] = true;
			paths.push_back(k);
			dfs(k);
			paths.pop_back();
			visited[i][k] = visited[k][i] = false;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int delim, edge;
	while (cin >>n>>len) {
		adj.clear();
		adj.resize(n);
		for(int i=0; i<n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> edge;
				if (edge)
					adj[i].push_back(j);
			}
		sol = false;
		memset(visited, 0, sizeof visited);
		dfs(0);
		if (!sol) cout << "no walk of length "<<len<<'\n';
		if (cin >> delim) cout << '\n';
	}
}