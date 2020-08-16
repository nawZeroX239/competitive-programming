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
const int N = 1000;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, n, k, m, step, x, y;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		m = 0;
		for (step=1; m+step< k; ++step) {
			m += step;
		}

		x = n - step;
		y = n - step + 1;
		if (m+step == k) {
			for (int i = 1; i <= n; ++i) {
				if (i >= x && i <= y) {
					cout << 'b';
				} else {
					cout << 'a';
				}
			}
		} else {
			// x--;
			y = n - (k - m - 1);
			for (int i = 1; i <= n; ++i) {
				if (i == x || i == y) {
					cout << 'b';
				}else {
					cout << 'a';
				}
			}
		}
		cout << '\n';
	}
}
