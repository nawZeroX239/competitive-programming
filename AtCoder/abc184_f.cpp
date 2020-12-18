#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
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

#define INF 1e9
#define  EPS 1e-9
#define N 5005
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int tx[] = { 0, 0, 1, -1 };
int ty[] = { -1, 1, 0, 0 };

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int toInt(string& s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

void solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	auto t1 = chrono::high_resolution_clock::now();
	solve();
	auto t2 = chrono::high_resolution_clock::now();
	double dt = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() / 1000.0;
	
	//cout << dt << 's' << '\n';
	return 0;
}

long long B[1048576], sum, ans;
void solve() {
	int n, t, arr[40];

	cin >> n >> t;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int g = n / 2;
	int h = n - g;
	int sz = 1 << g;
	// compute first half
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < g; ++j) {
			if ((i >> j) & 1) {
				B[i] += arr[j];
			}
		}
	}
	sort(B, B + sz);
	// compute second half & binary search
	ans = 0;
	for (int i = 0; i < (1 << h); ++i) {
		sum = 0;
		for (int j = 0; j < h; ++j) {
			if ((i >> j) & 1) {
				sum += arr[j + g];
			}
		}
		if (sum > t) continue;
		auto it = upper_bound(B, B + sz, t - sum);
		--it;
		ans = max(ans, sum + *it);
	}

	cout << ans << '\n';

}