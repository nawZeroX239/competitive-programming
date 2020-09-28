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
#define N  10000

using namespace std;

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

int c[] = { 1, 5, 10, 25, 50};
long long dp[7490][32];
long long recur(int n, int i) {
	if (n == 0) {
		return 1;
		// cout << k <<' ' << __builtin_popcount(k)<<'\n';
		// return __builtin_popcount(k) > 1;
	}
	if (dp[n][i] != -1) return dp[n][i];
	long long x = 0;
	for (int j = i; j < 5; ++j) {
		if (c[j] <= n) {
			x += recur(n - c[j], j);
		}
	}

	return dp[n][i] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	memset(dp, -1, sizeof dp);
	recur(7489, 0);
	dp[0][0] = 1;
	while (cin >> n) {
		cout << dp[n][0] << '\n';
	}
}