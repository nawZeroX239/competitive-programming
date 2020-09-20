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
	int n;
	ss >> n;
	return n;
}
int dp[10000][100], arr[10000];
int n, k;
int solve(int i, int sum) {
	if (i == n) {
		if (sum == 0) return 1;
		return 0;
	}

	if (dp[i][sum] != -1) return dp[i][sum];

	int x1 = (sum - arr[i])%k;
	int x2 = (sum + arr[i])%k;
	if (x1 < 0) x1 += k;
	if (x2 < 0) x2 += k;

	return dp[i][sum] = solve(i + 1, x1) | solve(i + 1, x2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		memset(dp, -1, sizeof dp);
		if (solve(0, 0)) {
			cout << "Divisible" << '\n';
		} else {
			cout <<"Not divisible" << '\n';

		}
	}

}