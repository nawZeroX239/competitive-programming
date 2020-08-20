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

const int N = 1e5;
const long double EPS = 1e-9;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, ans, x, y, tc=1;
	double r, s;
	bool ok;

	while (cin >> n >> d) {
		if (n == 0 && d == 0) break;
		vector<pair<double, double>> coord(n);
		ok = true;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			if (y > d) ok = false;
			r = sqrt(d * d - y * y);
			coord[i].first = x - r;
			coord[i].second = x + r;
		}
		if (!ok) {
			cout <<"Case "<<tc++<<": "<< -1 << '\n';
			continue;
		}
		sort(coord.begin(), coord.end());
		s = coord[0].second, ans = 0;
		for (int i = 0; i < n;) {
			for (; i < n && coord[i].first <= s; ++i ) {
				s = min(s, coord[i].second);
			}
			++ans;
			if (i < n) s = coord[i].second;
		}

		cout << "Case " << tc++ << ": " << ans << '\n';
	}
}