#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <iomanip>
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <cmath>
#include <bitset>
#include <numeric>
using namespace std;

const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 1000;
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

bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.second > right.second;
}

bool lb_pred(const pair<int, int>& left, const int right) {
	return left.first < right;
}


pair<int, int> items[N];
int n, g, dp[N][31];
int knapsack(int remW, int i) {
	if (i == n) {
		return  0;
	}
	if (dp[i][remW] != -1) return dp[i][remW];
	int r1 = 0, r2 = knapsack(remW, i + 1);

	if (items[i].second <= remW) {
		r1 = items[i].first + knapsack(remW - items[i].second, i + 1);
	}
	
	return  dp[i][remW] = max(r1, r2);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T, ans, capacity;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> items[i].first >> items[i].second;
		}
		cin >> g;
		ans = 0;
		for (int i = 0; i < g; ++i) {
			cin >> capacity;
			// cout << capacity << '\n';
			memset(dp, -1, sizeof dp);
			ans += knapsack(capacity, 0);
		}
		cout << ans << '\n';
	}
	return 0;
}