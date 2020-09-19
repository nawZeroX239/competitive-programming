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

int dp[105][105];
int n, k;
long long solve(int sum, int cnt) {
	if (cnt == k) {
		if(sum == n) return 1;
		return 0;
	}
	if (dp[sum][cnt] != -1) return dp[sum][cnt];
	int ans = 0;
	for (int i = 0; i <= n-sum; ++i) {
		ans += solve(i + sum, cnt + 1);
	}
	return dp[sum][cnt]= ans % 1000000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n >> k) {
		if (n == 0 && k == 0) break;
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << '\n';
	}

}