#include <iostream>
#include <string>
#include <algorithm>
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
#include <cmath>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int N = 500;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int g[N][N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, q, l, u, ans;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> g[i][j];
			}
		}
		cin >> q;
		while (q--) {
			cin >> l >> u;
			ans = 0;
			for (int r = 0; r < n; ++r) {
				int c = lower_bound(g[r], g[r] + m, l) - g[r];
				// cout <<"c: "<< c << '\n';
				if (c < m) {
					for (int sz = 1; c + sz - 1 < m &&
									 r + sz - 1 < n; ++sz) {
						if (g[r + sz - 1][c + sz - 1] > u) {
							break;
						}
						ans = max(ans, sz);
					}
				}
			}

			cout << ans << '\n';
		}
		cout << '-' << '\n';
	}

}