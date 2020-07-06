#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cost, t, n, m, x, y, avail;
	string s;
	cin >> t;
	while (t) {
		cost = 0;
		cin >> n >> m >> x >> y;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			avail = 1;
			for (int j = 0; j < m; ++j) {
				if (s[j] == '.') {
					if (j - 1 >= 0 && s[j] == s[j - 1] && avail) {
						cost = min(cost - x + y, cost + x);
						avail = 0;
					} else {
						cost = cost + x;
						avail = 1;
					}
				}
			}
		}
		cout << cost << '\n';
		--t;
	}
}