#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
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
const int N = 3005;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}

int n, m, ans;
bool g[N][N];

void solve() {
	for (int a = 1; a <= n-2; ++a) {
		for (int b = a + 1; b <= n-1; ++b) {
			if(g[a][b])
			for (int c = b + 1; c <= n; ++c) {
				if (g[a][b] && g[b][c] && g[c][a])
					++ans;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	int x, y;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		memset(g, 0, sizeof g);
		ans = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			g[x][y] = g[y][x] = true;
		}

		solve();
		printf("%d\n", ans);
	}

}
