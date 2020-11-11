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

int dp[1001][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, x, w[1000], page[1000];
	cin >> n >> x;
	for (int i = 0; i < n; ++i) cin >> w[i];
	for (int j = 0; j < n; ++j) cin >> page[j];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= x; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (w[i - 1] <= j) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + page[i - 1]);
			}
		}
	}

	cout << dp[n][x] << '\n';
}