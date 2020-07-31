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
const int N = 24;
const int K = 5;
template <class T> T gcd(T a, T b) {
	if (b == 0){ return a;} 
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}


int sol[5];
int g[5][5];
int temp[5];

int getCost() {
	int x = 0, dx;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			dx = INT_MAX;
			for (int k = 0; k < 5; ++k) {
				dx = min(dx, g[i][j] * (abs(temp[k] / 5 - i) + abs(temp[k] % 5 - j)));
			}
			x += dx;
		}
	}

	return x;
}

void solve() {
	int best = INT_MAX, cost;
	for (int a = 0; a <= N-4; ++a) {
		for (int b = a + 1; b <= N-3; ++b) {
			for (int c = b + 1; c <= N-2; ++c) {
				for (int d = c + 1; d <= N-1; ++d) {
					for (int e = d + 1; e <= N; ++e) {

						temp[0] = a; temp[1] = b; temp[2] = c; temp[3] = d; temp[4] = e;
						cost = getCost();

						if (cost < best) {
							sol[0] = a; sol[1] = b; sol[2] = c; sol[3] = d; sol[4] = e;
						}
						best = min(cost, best);
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc, q, r, c, amt;
	cin >> tc;
	while (tc--) {
		memset(g, 0, sizeof g);
		cin >> q;
		for (int i = 0; i < q; ++i) {
			cin >> r >> c >> amt;
			g[r][c] = amt;
		}
		
		solve();
		cout << sol[0] << ' ' << sol[1] << ' ' << sol[2] << ' ' << sol[3] << ' ' << sol[4] << '\n';
	}
	
}
		