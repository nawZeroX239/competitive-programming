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
#define N 10000
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

// https://math.stackexchange.com/questions/3266257/number-of-ways-two-knights-can-be-placed-such-that-they-dont-attack/3266324#3266324
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << 0 << '\n';
	if (n > 1)
		cout << 6 << '\n';
	for (long long k = 3; (int)k <= n; ++k) {
		long long ans = (k * k * (k * k - 1)) / 2 - 4 * (k - 1) * (k - 2);
		cout << ans << '\n';
	}
}