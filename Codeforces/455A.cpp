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

const long double EPS = 1e-9;
const int N = 20;

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

int A[100005];
long long dp[100005];
long long solve(int i) {
	if (i > 100000) return 0;
	if (dp[i] != -1) return dp[i];
	return dp[i] = max((long long)i * A[i] + solve(i + 2), solve(i + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		A[m]++;
	}
	
	memset(dp, -1, sizeof dp);
	cout << solve(1) << '\n';
}