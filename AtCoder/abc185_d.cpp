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

int A[2 * (int)1e5];
void solve() {
	int n, m, k=INF, ans, x;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> A[i];
	}

	sort(A, A + m);
	if (A[0] > 1) {
		k = A[0] - 1;
	}

	if (A[m - 1] != n) {
		k = min(k, n - A[m - 1]);
	}

	for (int i = 1; i < m; ++i) {
		// cout << A[i] - A[i - 1] << '\n';
		if (A[i]-1 == A[i - 1]) continue;
		k = min(k, A[i] - A[i - 1] - 1);
	}
	if (m == n) {
		cout << 0 << '\n';
		return;
	}
	if (m == 0) {
		cout << 1 << '\n';
		return;
	}
	ans = 0;
	if (A[0] > 1) {
		x = A[0] - 1;
		ans += x/k ;
		if (x % k != 0) ans++;
	}
	if (A[m - 1] < n) {
		x = n - A[m - 1];
		ans += x / k;
		if (x % k != 0) ++ans;
	}
	for (int i = 1; i < m; ++i) {
		x = A[i] - A[i - 1] - 1;
		ans += x / k;
		if (x % k != 0) ++ans;
	}
	cout << ans << '\n';
	
}