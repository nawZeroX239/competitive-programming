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
#define N 26
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

int dp[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, L, W, ans;
	char ch;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			dp[i][j] = ch - '0' - dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
		}
	}

	ans = 0;
	for (int x1 = 1; x1 <= n; ++x1) {
		for (int y1 = 1; y1 <= m; ++y1) {
			for (int x2 = x1; x2 <= n; ++x2) {
				L = x2 - x1 + 1;
				for (int y2 = y1; y2 <= m; ++y2) {
					W = y2 - y1 + 1;
					if (dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x2][y1 - 1] - dp[x1 - 1][y2] == 0) {
						ans = max(ans, 2 * (L + W));
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}