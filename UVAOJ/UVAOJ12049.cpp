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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define N 30001
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, ans, m, n, x;
	cin >> t;
	while (t) {
		multiset<int> P, Q;
		cin >> m >> n;
		for (int i = 0; i < m; ++i) {
			cin >> x;
			P.insert(x);
		}

		for (int i = 0; i < n; ++i) {
			cin >> x;
			Q.insert(x);
		}
		
		auto it1 = P.begin();
		auto it2 = Q.begin();
		ans = 0;
		while (it1 != P.end() && it2 != Q.end()) {
			if (*it1 > * it2) {
				++it2;
				++ans;
			} else if (*it1 < *it2) {
				++it1;
				++ans;
			} else {
				++it1;
				++it2;
			}
		}

		while (it1 != P.end()) {
			++ans;
			++it1;
		}

		while (it2 != Q.end()) {
			++ans;
			++it2;
		}

		cout << ans << '\n';
		--t;
	}

}
