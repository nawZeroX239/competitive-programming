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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n;
	int g[300][300];
	cin >> T;
	while (T--) {
		cin >> n;
		
		for (int i = 0; i < 2 * n; ++i) {
			for (int j = 0; j < 2 * n; ++j) {
				if (i < n && j < n) {
					cin >> g[i][j];
					g[i + n][j] = g[i][j + n] = g[i + n][j + n] = g[i][j];
				}
				if (i > 0) {
					g[i][j] += g[i - 1][j];
				}
				if (j > 0) {
					g[i][j] += g[i][j - 1];
				}
				if (i > 0 && j > 0) {
					g[i][j] -= g[i - 1][j - 1];
				}
			}
		}

		int ans = -100 * 75 * 75;
		for (int x1 = 0; x1 < n; ++x1) {
			for (int y1 = 0; y1 < n; ++y1) {
				for (int x2 = x1; x2 < n + x1; ++x2) {
					for (int y2 = y1; y2 < n + y1; ++y2) {
						int temp = g[x2][y2];
						if (x1 > 0) {
							temp -= g[x1 - 1][y2];
						}
						if (y1 > 0) {
							temp -= g[x2][y1 - 1];
						}
						if (x1 > 0 && y1 > 0) temp += g[x1 - 1][y1 - 1];
						ans = max(ans, temp);
					}
				}
			}
		}
		cout << ans << '\n';
	}
}