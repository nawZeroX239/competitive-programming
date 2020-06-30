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
#include <numeric>
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

#define EPS 1e-9
#define N 12
#define PIXEL 1024
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline void newline() { cout << '\n'; }
inline void split(vector<string>& vect, string& str, char delim) {
	string each;
	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it != delim)
			each.push_back(*it);
		else {
			vect.push_back(each);
			each.clear();
		}
	}
	if (each.size()) vect.push_back(each);
}

inline bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.first < right.first;
}

inline bool lb_pred(const pair<int, int>& left, int right) {
	return left.first < right;
}


long long s, d, m[N];
long long ans;

void backtrack(int i, long long total) {
	if (i >= 5 && accumulate(m + i - 5, m + i, 0LL) >= 0)
		return;

	if (i>=N) {
		ans = max(ans, total);
		return;
	}

	m[i] = s;
	backtrack(i + 1, total + s);
	m[i] = -d;
	backtrack(i + 1, total - d);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> s>>d) {
		ans = LLONG_MIN;
		memset(m, 0, sizeof m);
		backtrack(0, 0);
		if (ans < 0) printf("Deficit\n");
		else printf("%d\n", ans);
	}
}