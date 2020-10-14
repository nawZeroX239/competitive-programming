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

string g[100];
int n;
void floodfill(int i, int j, bool vert) {
	if (i < 0 || j < 0 || i >= n || j >= n) return;
	if (g[i][j] != '@' && g[i][j] != 'x') return;
	g[i][j] = 'S';

	if (vert) {
		floodfill(i + 1, j, vert);
		floodfill(i - 1, j, vert);
	} else {
		floodfill(i, j - 1, vert);
		floodfill(i, j + 1, vert);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, tc = 1;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> g[i];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == 'x') {
					if ((i > 0 && (g[i - 1][j] == '@' || g[i - 1][j] == 'x'))
						|| (i+1<n && (g[i + 1][j] == '@' || g[i + 1][j] == 'x'))) {
						floodfill(i, j, true);
					} 
					if((j > 0 && (g[i][j - 1] == '@' || g[i][j - 1] == 'x'))
						|| (j + 1 < n && (g[i][j + 1] == '@' || g[i][j + 1] == 'x'))) {
						floodfill(i, j, false);
					}
					g[i][j] = 'S';
					++ans;
				}
			}
		}
		cout <<"Case "<<tc++<<": "<<ans << '\n';
		
	}
}