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

const long double EPS = 1e-9;
const int N = 100001;

using namespace std;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}
int toInt(string& s) {
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}

bool same_sign(int left, int right) {
	return (left < 0 && right < 0) ||
		(left > 0 && right > 0);
}

int a[N], q[N];
bool b[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m, x, c, l;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	c = 0;
	for (int i = n; i > 0; --i) {
		if (!b[a[i]]) {
			b[a[i]] = true;
			++c;
		}
		q[i] = c;
	}
	for (int i = 0; i < m; ++i) {
		cin >> l;
		cout << q[l] << '\n';
	}
}