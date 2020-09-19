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

int dp[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n, t, x, y;
	while (cin >> m >> n >> t) {
		memset(dp, -1, sizeof dp);
		dp[0] = 0;
		for (int i = min(n, m); i <= t; ++i) {
			if (i >= n && dp[i - n] != -1) {
				dp[i] = max(dp[i], dp[i - n] + 1);
			}
			if (i >= m && dp[i - m] != -1) {
				dp[i] = max(dp[i], dp[i - m] + 1);
			}
		}
		if (dp[t] >= 0) {
			cout << dp[t] << '\n';
		} else {
			for (int k = t - 1; k >= 0; --k) {
				if (dp[k] >= 0) {
					cout << dp[k] << ' ' << t - k << '\n';
					break;
				}
			}
		}
	}

}