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

int dp[1000][1000];
string grid[1000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m = 1e9 + 7;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
	if (grid[0][0] == '*') {
		cout << 0 << '\n';
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '*') continue;
			if (i - 1 >= 0 && grid[i-1][j] != '*') (dp[i][j] += dp[i - 1][j])%=m;
			if (j - 1 >=0 && grid[i][j - 1] != '*') (dp[i][j] += dp[i][j - 1]) %= m;
		}
	}

	cout << dp[n-1][n-1]<< '\n';
}