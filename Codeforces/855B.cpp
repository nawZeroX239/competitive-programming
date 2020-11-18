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

#define INF 1e9
#define  EPS 1e-9
#define N 100000
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long p[N], q[N], r[N], x, a, b, c, ans;
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		p[i] = x * a;
		q[i] = x * b;
		r[i] = x * c;
	}
	for (int i = 1; i < n; ++i) p[i] = max(p[i], p[i - 1]);
	for (int i = n - 2; i >= 0; --i) r[i] = max(r[i], r[i + 1]);
	ans = p[0] + q[0] + r[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, p[i] + q[i] + r[i]);
	}
	cout << ans << '\n';
}