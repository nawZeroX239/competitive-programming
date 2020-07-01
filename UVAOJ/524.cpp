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
#define N 17
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

// int P[N], Q[N];

vector<int> ans;
bool arr[N];
int n;

bool isPrime(int x) {
	for (int d = 2; d * d <= x; d++) {
		if (x % d == 0)
			return false;
	}
	return true;
}

void backtrack() {
	if (ans.size() == n && isPrime(ans[0]+ans[ans.size()-1])) {
		cout << ans[0];
		for (int i = 1; i < n; ++i)
			cout << ' ' << ans[i];
		cout << '\n';
		return;
	}

	if (ans.size() >= n) return;
	for (int i = 2; i <= n; ++i) {
		if (arr[i]) continue;
		if (isPrime(ans[ans.size() - 1] + i)) {
			arr[i] = true;
			ans.push_back(i);
			backtrack();
			ans.pop_back();
			arr[i] = false;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc = 1;
	while (cin >> n) {
		if (tc > 1) cout << '\n';
		cout << "Case " << tc << ":\n";
		if (n == 1) {
			cout << n << '\n';
		}else {
			ans.clear();
			ans.push_back(1);
			backtrack();
		}

		++tc;
	}
}