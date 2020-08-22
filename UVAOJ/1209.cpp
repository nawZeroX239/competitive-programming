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
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 52;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int compute(string& s) {
	int cmin = INT_MAX;
	for (int i = 1; i < s.length(); ++i) {
		cmin = min(cmin, abs(s[i] - s[i - 1]));
	}

	return cmin;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, prev, ans;
	int cmax, cmin;
	bool more, less;
	while (cin >> s) {
		prev = ans = s;
		cmax = compute(s);
		more = less = true;
		for (int i = 0;  i < 10; ++i) {
			if (more) {
				more = next_permutation(s.begin(), s.end());
				if (!more) continue;

				cmin = compute(s);
				if (cmax < cmin) {
					ans = s;
					cmax = cmin;
				}
			}

			if (less) {
				less = prev_permutation(prev.begin(), prev.end());
				if (!less) continue;

				cmin = compute(prev);
				if (cmax <= cmin) {
					ans = prev;
					cmax = cmin;
				}
			}
		}

		cout << ans << cmax << '\n';
	}
}
