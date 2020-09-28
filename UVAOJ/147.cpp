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
#define  EPS 1e-9
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

int c[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[30001][11];
long long recur(int n, int k) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	long long x = 0;
	if (dp[n][k] != -1) return dp[n][k];
	for (int i = k; i < 11; ++i) {
		x += recur(n - c[i], i);
	}

	return dp[n][k] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	double n;
	memset(dp, -1, sizeof dp);
	recur(30000, 0);

	while (scanf("%lf", &n)) {
		int m = static_cast < int>(100 * n + 0.5);
		if (n < EPS) break;
		// cout << m << '\n';
		printf("%6.2f%17lld\n", n, recur(m, 0));
	}
}