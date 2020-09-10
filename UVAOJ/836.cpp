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

int g[N+1][N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n, an, area, w, l;
	string s;
	getline(cin, s);
	T = toInt(s);
	getline(cin, s);
	while (T--) {
		memset(g, 0, sizeof g);
		n = 1;
		while (true) {
			getline(cin, s);
			if (s.length() == 0) break;
			// cout << s << '\n';
			for (int i = 1; i <= s.length(); ++i) {
				g[n][i] = s[i - 1] - '0' + g[n-1][i] + g[n][i-1] - g[n-1][i-1];

			}

			++n;
		}

		an = 0;
		for (int x1 = 1; x1 < n; ++x1) {
			for (int y1 = 1; y1 < n; ++y1) {
				for (int x2 = x1; x2 < n; ++x2) {
					l = x2 - x1 + 1;
					for (int y2 = y1; y2 < n; ++y2) {
						w = y2 - y1 + 1;
						area = g[x2][y2] + g[x1 - 1][y1 - 1] - g[x2][y1 - 1] - g[x1 - 1][y2];
						if (area == l * w) {
							an = max(an, area);
						}
					}
				}
			}
		}
		cout << an << '\n';
		if (T) cout << '\n';
	}
}