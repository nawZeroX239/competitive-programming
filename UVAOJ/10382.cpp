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

	int n, m, L, W, p, q, ans, next;
	double R, H, start, end, cur;

	while (cin >> n >> L >> W) {
		vector<pair<double, double>> gaps;
		H = (double)W / 2;
		for (int i = 0; i < n; ++i) {
			cin >> p >> q;
			R = (double)q * q - H * H;
			// cout << "R < 0 " << (R < 0) << '\n';

			if (R < 0) continue;
			R = sqrt(R);
			gaps.push_back(make_pair(p - R, p + R));
		}

		sort(gaps.begin(), gaps.end());

		m = gaps.size(), ans = end = 0;
		
		//for (int i = 0; i < m; ++i) {
		//	cout << gaps[i].first << ' ' << gaps[i].second << '\n';
		//}

		for (int j, i = 0; i < m; ++i) {
			next = -1, cur = end;
			for (j = i; j < m && gaps[j].first <= end; ++j) {
				if (gaps[j].second > cur) {
					next = j;
					cur = gaps[next].second;
				}
			}
			if (next == -1) break;
			++ans;
			end = cur;
			if (end >= L) break;
			i = j - 1;
		}

		if (end < L) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
}
