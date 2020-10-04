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

// translation
int tx[] = { 0, 0, 1,  1, 1, -1, -1, -1 };
int ty[] = {-1, 1, 0, -1, 1,  0, -1,  1 };
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

char g[100][100], n, m;
int floodfill(int r, int c, char u, char v) {
	if (r < 0 || c < 0 || r > n - 1 || c > m - 1) {
		return 0;
	}
	if (g[r][c] != u) return 0;
	int ans = 1;
	g[r][c] = v;
	for (int i = 0; i < 8; ++i) {
		ans += floodfill(r + tx[i], c + ty[i], u, v);
	}

	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc, r, c;
	string s;
	getline(cin, s);
	tc = toInt(s);
	getline(cin, s);
	while (tc--) {
		n = 0; m = -1;
		while (getline(cin, s)) {
			if (s[0] >= '0' && s[0]<='9') break;
			if (m == -1) m = s.length();
			for (int i = 0; i < m; ++i) {
				g[n][i] = s[i];
				/// cout << g[n][i] << '\n';
			}
			++n;
		}

		do {
			if (s.length() == 0) break;
			stringstream ss(s);
			ss >> r >> c;
			cout << floodfill(r-1, c-1, 'W', '.')<<'\n';
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) if (g[i][j] == '.') g[i][j] = 'W';
			}
		} while (getline(cin, s));
		if (tc) cout << '\n';
	}
}