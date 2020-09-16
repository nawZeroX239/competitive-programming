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
const int N = 100;
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

int c[N], sum, n, dp[100][50005];
int cc(int a, int b, int i) {
	if (i >= n) {
		return abs(a - b);
	}

	if (dp[i][a] != -1 ) return dp[i][a];
	return dp[i][a] = dp[i][b] = min(cc(a + c[i], b, i + 1), cc(a, b + c[i], i + 1));
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		sum  = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
			sum += c[i];
		}
		
		memset(dp, -1, sizeof dp);
		cout << cc(0, 0, 0) << '\n';
	}
	return 0;
}
