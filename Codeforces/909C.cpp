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
#define N 5005
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

long long dp[N][N];
long long mod = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	char statements[N];
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> statements[i];
	}

	dp[0][0] = 1;
	statements[0] = 'f';
	for (int j = 1; j <= n; ++j) dp[1][j] = 1;
	for (int i = 1; i <= n; ++i) {
		if (statements[i - 1] == 's') {
			dp[i][n] = dp[i - 1][n];
			for (int j = n - 1; j > 0; --j) {
				dp[i][j] = (dp[i][j + 1] + dp[i - 1][j])%mod;
			}
		} else {	
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	long long ans = 0;
	for (int j = 1; j <= n; ++j) {
		(ans += dp[n][j])%=mod;
	}

	cout <<ans << '\n';
	return 0;
}