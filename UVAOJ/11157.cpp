#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
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
#include <climits>
#include <cmath>
#include <bitset>
#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 100;

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

//bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
//	return left.second > right.second;
//}
//
//bool lb_pred(const pair<int, int>& left, const int right) {
//	return left.first < right;
//}
//

int a[N];
char c[N];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T, tc = 1, n, d, k, l, ans;
	string s;
	cin >> T;
	while (T--) {
		cin >> n >> d;
		
		for (int i = 0; i < n; ++i) {
			cin >> s;
			c[i] = s[0];
			s = s.substr(2);
			a[i] = toInt(s); 
		}

		ans = -1;
		k = l = 0;
		for (int i = 0; i < n;) {
			if (c[i] == 'S') {
				if (i + 1 < n && c[i + 1] == 'S') {
					ans = max(ans, max(a[i] - k, a[i+1] - l));
					l = a[i+1], k = a[i];
					i += 2;
				} else {
					ans = max(ans, a[i] - k);
					k = a[i];
					i += 1;
				}
			} else {
				ans = max(ans, a[i] - min(k, l));
				k = l = a[i];
				i += 1;
			}
		}
		ans = max(ans, d - min(k, l));
		cout << "Case " << tc++ << ": "<<ans<<'\n';
	}
	return 0;
}