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

long long dp[100000][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, mod = 1e9 + 7, x, y, op[3] = { -1, 0, 1 };
	long long ans;
	cin >> n >> m;
	cin >> x;
	if (x == 0) {
		for (int i = 1; i <= m; ++i) {
			dp[0][i] = 1;
		}
	} else {
		dp[0][x] = 1;
	}

	for (int i = 1; i < n; ++i) {
		cin >> x;
		if (x == 0) {
			for (int j = 1; j <= m; ++j) {
				for (int k = 0; k < 3; ++k) {
					y = j + op[k];
					if (y >= 1 && y <= m) {
						(dp[i][j] += dp[i - 1][y]) %= mod;
					}
				}
			}
		} else {
			for (int j = 0; j < 3; ++j) {
				y = x + op[j];
				if (y >= 1 && y <= m) {
					(dp[i][x] += dp[i - 1][y]) %= mod;
				}
			}
		}
	}

	ans = 0;
	for (int i = 1; i <= m; ++i) {
		(ans += dp[n - 1][i]) %= mod;
	}

	cout << ans << '\n';
}