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

	int tc, n, x, y, odd, even;
	cin >> tc;
	while (tc--) {
		cin >> n >> x;
		odd = even = 0;
		for (int i = 0; i < n; ++i) {
			cin >> y;
			if (y & 1) ++odd;
			else ++even;
		}

		bool sol = false;
		for (int i = 0; i <= x; ++i) {
			for (int j = 0; j <= x-i; ++j) {
				if (i > even || j > odd) continue;
				// i's even
				// j's odd
				if (i + j == x) {
					if (j & 1) {
						sol = true;
						break;
					}
				}
			}
			if (sol) break;
		}
		if (sol) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}
