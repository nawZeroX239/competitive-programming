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
const int N = 25;

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

int ar[N], rk[N], memo[N], mp[N];
int ans;
int solve(int k) {
	if (k == 0) return 1;
	if (memo[k] != -1) return memo[k];
	int res;
	memo[k] = 1;
	for (int i = 0; i < k; ++i) {
		res = solve(i);
		if (mp[rk[i]] < mp[rk[k]]) {
			memo[k] = max(memo[k], res + 1);
			// order[i] = order[k] = true;
		}
	}

	ans = max(ans, memo[k]);
	return memo[k];
}
void reads(string& s, int& k) {
	stringstream ss(s);
	for (k = 0; ss >> ar[k]; ++k) {

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	string s;
	while (true) {
		while (true) {
			if (getline(cin, s)) {
				reads(s, k);
				if (k == 1) {
					n = ar[0];
					getline(cin, s);
					reads(s, k);
					for (int i = 0; i < n; ++i) {
						// mp[ar[i] - 1] = i;
						mp[i] = ar[i] - 1;
					}
				} else {
					// process
					for (int i = 0; i < n; ++i) {
						rk[ar[i] - 1] = i;
					}
					ans = 1;
					memset(memo, -1, sizeof memo);
					solve(n - 1);
					cout << ans << '\n';
				}
			} else {
				return 0;
			}
		}
	}
	
}