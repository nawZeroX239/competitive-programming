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
long long arr[200], dp[200][20][20];
int n, q, d, m;
long long solve(int i, int k, int sum) {
	if (k == m) {
		return sum == 0;
	}
	if (i == n) return 0;
	if (dp[i][k][sum] != -1) return dp[i][k][sum];
	int temp = (sum + arr[i]) % d;
	if (temp < 0) temp += d;
	return dp[i][k][sum] = solve(i + 1, k, sum) + solve(i + 1, k + 1, temp);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	while (cin >> n >> q) {
		if (n == 0 && q == 0) break;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << "SET " << T++ << ':' << '\n';
		for (int i = 0; i < q; ++i) {
			memset(dp, -1, sizeof dp);
			cin >> d>>m;
			cout <<"QUERY "<<i+1<<": "<<solve(0, 0, 0) << '\n';
		}

	}
	
}