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
const int N = 200000;

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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, last, cur;
	long long ans;
	cin >> T;
	while (T--) {
		cin >> n>> last;
		ans = 0;
		for (int i = 1; i < n; ++i) {
			cin >> cur;
			if (same_sign(last, cur)) {
				last = max(last, cur);
			} else {
				ans += last;
				last = cur;
			}
		}
		ans += last;
		cout << ans << '\n';
		
	}


}