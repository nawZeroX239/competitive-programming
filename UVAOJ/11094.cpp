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
int x[] = { 0, 0, 1, -1 };
int y[] = { -1, 1, 0, 0 };
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

int n, m, ctr;
string g[20];
void floodfill(int i, int j, char u, char v) {
	if (i < 0 || i >= n) return;
	if (j < 0) j = m - 1;
	else if (j >= m) j = 0;
	if (g[i][j] != u) return;
	g[i][j] = v;
	++ctr;
	for (int k = 0; k < 4; ++k) {
		floodfill(x[k] + i, y[k] + j, u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int c, d, ans;
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			cin >> g[i];
		}
		cin >> c >> d;
		char u = g[c][d], v = 'S';
		floodfill(c, d, u, v);
		ans = 0;
		//for (int i = 0; i < n; ++i) {
		//	cout << g[i] << '\n';
		//}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == u) {
					ctr = 0;
					floodfill(i, j, u, v);
					// cout << "ctr:" << ctr << '\n';

					ans = max(ans, ctr);
				}
			}
		}

		cout << ans << '\n';
	}

}