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
#define N 20000
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int x[] = { 0, 0, 1, -1 };
int y[] = { -1, 1, 0, 0 };

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

int dp[(int)1e6 + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	int coins[100];
	for (int i = 0; i <= (int)1e6; ++i) dp[i] = 1e9;

	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
		// dp[coins[i]] = 1;
	}

	dp[0] = 0;
	for (int i = 1; i <= x; ++i) {
		int res = 1e9;
		for (int j = 0; j < n; ++j) {
			if (i >= coins[j] && dp[i - coins[j]] + 1 < res ) {
				res = dp[i - coins[j]] + 1;
			}
		}

		if (res !=(int)1e9) {
			dp[i] = res;
		}
	}

	if (dp[x] == (int)1e9) cout << -1 << '\n';
	else cout << dp[x] << '\n';
}

