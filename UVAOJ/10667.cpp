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
const int N = 105;

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

int g[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, r1, r2, c1, c2, n, s, area, an;
	cin >> T;
	while (T--) {
		cin >> n >> s;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				g[i][j] = 1;
			}
		}
		while (s--) {
			cin >> r1 >> c1 >> r2 >> c2;
			for (int i = r1; i <= r2; ++i) {
				for (int j = c1; j <= c2; ++j) {
					g[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j) {
				g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
			}
		}
		an = 0;
		for (int x1 = 1; x1 <= n; ++x1) {
			for (int y1 = 1; y1 <= n; ++y1) {
				for (int x2 = x1; x2 <= n; ++x2) {
					for (int y2 = y1; y2 <= n; ++y2) {
						area = g[x2][y2] + g[x1 - 1][y1 - 1] - g[x2][y1 - 1] - g[x1 - 1][y2];
						if ((x2 - x1 + 1) * (y2 - y1 + 1) == area) {
							an = max(an, area);
						}
					}
				}
			}
		}
		cout << an << '\n';
	}

}