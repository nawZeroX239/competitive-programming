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

int dp[101][3]; // dp[day][rest, sport, write contest]
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a[100];
	
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i-1][1], dp[i-1][2]));
		dp[i][1] = dp[i][2] = INF;
		if (a[i - 1] == 1 || a[i - 1] == 3) {
			dp[i][2] = min(dp[i - 1][0], dp[i-1][1]);
		}

		if (a[i - 1] == 2 || a[i - 1] == 3) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
}