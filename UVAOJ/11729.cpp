#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <iomanip>
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 1000;

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

bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.second > right.second;
}

bool lb_pred(const pair<int, int>& left, const int right) {
	return left.first < right;
}

pair<int, int> a[N];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	int t0, t1, tc = 1;
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a, a + n, sort_pred);
		t0 = a[0].first;
		t1 = t0 + a[0].second;
		for (int i = 1; i < n; ++i) {
			t0 += a[i].first;
			t1 = max(t1, t0 + a[i].second);
		}
		cout << "Case " << tc++ << ": " << max(t0, t1) << '\n';
	}
}