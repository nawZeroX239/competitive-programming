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

int n, k, m;
long long dp[50][55][55];
long long recur(int x, int y, int z) {
	if (x == n) {
		return y == k;
	}
	if (dp[x][y][z] != -1) return dp[x][y][z];
	long long ans = 0;
	if (z < m) {
		ans = recur(x + 1, y, z + 1);
	} 

	if (y < k) {
		ans += recur(x + 1, y + 1, 1);
	}
	return dp[x][y][z] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (cin >> n >> k >> m) {
		memset(dp, -1, sizeof dp);
		cout << recur(1, 1, 1) << '\n';
	}

}