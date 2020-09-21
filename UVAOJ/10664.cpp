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

int w[20], dp[20][201];
int n, total;
int solve(int i, int sum) {
	if (i == n) {
		return 2 * sum == total;
	}
	if (dp[i][sum] != -1) return dp[i][sum];
	return dp[i][sum] = solve(i + 1, sum + w[i]) | solve(i + 1, sum);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	string ln;
	getline(cin, ln);
	T = toInt(ln);
	while (T--) {
		getline(cin, ln);
		stringstream ss(ln);
		// cout << "ln:" << ln << '\n';
		total = 0;
		for (n = 0; ss >> w[n]; ++n) {
			total += w[n];
		}
		// cout << total << ' ';
		if (total%2 != 0) {
			cout << "NO" << '\n';
		} else {
			memset(dp, -1, sizeof dp);
			if (solve(0, 0)) {
				cout << "YES" << '\n';
			} else {
				cout << "NO" << '\n';
			}
		}
	}
}