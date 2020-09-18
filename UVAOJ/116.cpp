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
#define EPS 1e-9
#define N = 500005

using namespace std;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}
int toInt(string& s) {
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}
int g[10][100];
struct node {
	int x, y, z;
};
tuple<int, int, string> dp[10][100];
int n, m;

tuple<int, int, string> min_tup(tuple<int, int, string> l, tuple<int, int,string> r) {
	if (get<0>(l) == get<0>(r)) {
		if (get<1>(l) < get<1>(r)) {
			return l;
		} else if (get<1>(l) > get<1>(r)) {
			return r;
		}
	} 
	
	if (get<0>(r) < get<0>(l)) {
		return r;
	}

	return l;
}

tuple<int, int, string> solve(int i, int j) {
	if (j + 1 == m) {
		return make_tuple(g[i][j], i, to_string(i+1));
	}
	if (get<0>(dp[i][j]) != -1) return dp[i][j];

	tuple<int, int, string> ret =
		min_tup(solve(i == 0 ? n - 1 : i - 1, j + 1), min_tup(solve(i, j + 1), solve((i + 1) % n, j + 1) ));
	get<0>(ret) += g[i][j];
	get<1>(ret) = i;
	get<2>(ret) = to_string(i+1) + ' ' + get<2>(ret);
	return dp[i][j] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans;
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> g[i][j];
				get<0>(dp[i][j]) = -1;
			}
		}
		

		tuple<int, int, string> ans, temp;
		get<0>(ans) = INF;
		for (int i = 0; i < n; ++i) {
			temp =  min(ans, solve(i, 0));
			if (get<0>(temp) < get<0>(ans)) {
				ans = temp;
			}
		}
		cout << get<2>(ans) << '\n';
		cout << get<0>(ans) << '\n';
	}
}