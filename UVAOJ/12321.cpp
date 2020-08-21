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

	int g;
	long long l, x, r, s, ans;
	bool ok;

	while (cin >> l >> g) {
		if (l == 0 && g == 0) break;
		vector<pair<long long, long long>> vii(g);
		for (int i = 0; i < g; ++i) {
			cin >> x >> r;
			vii[i].first = x - r, vii[i].second = x + r;
		}
		sort(vii.begin(), vii.end());
		ok = true, ans = 0, r = 0;
		for (int j, i = 0; i < g && r < l;) {
			for (s = j = i; j < g && vii[j].first<= r; ++j) {
				if (vii[s].second < vii[j].second) {
					s = j;
				}
			}

			if (i == j) {
				// cout << "Not Okay" << '\n';
				ok = false;
				break;
			}

			i = j;
			r = vii[s].second;
			++ans;
		}
		// cout <<"ans : "<< ans << '\n';
		if (r >= l) {
			cout << g-ans<< '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}