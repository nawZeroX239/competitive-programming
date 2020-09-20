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
#define N  10005

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

int price[20][20], f[20], dp[205][20];
int m, c;

int solve(int rem, int i) {
	if (i == c) {
		return m - rem;
	}
	if (dp[rem][i] != -1) return dp[rem][i];
	int best = -INF;
	for (int j = 0; j < f[i]; ++j) {
		if (price[i][j] <= rem) {
			best = max(best, solve(rem - price[i][j], i + 1));
		}
	}

	return dp[rem][i] = best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, k, ans;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof dp);

		cin >> m >> c;
		// cout << m << ' ' << c << '\n';
		for (int i = 0; i < c; ++i) {
			cin >> k;
			f[i] = k;
			for (int j = 0; j < k; ++j) {
				cin >> price[i][j];
			}
		}
		ans = solve(m, 0);
		if (ans < 0) {
			cout << "no solution" << '\n';
		} else {
			cout << ans << '\n';

		}
	}

}