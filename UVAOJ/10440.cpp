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
const int N = 1440;

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

int arr[N];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T, n, m, p, q, r, t;
	cin >> T;
	while (T--) {
		cin >> n >> t >> m;
		for (int i = 0; i < m; ++i) {
			cin >> arr[i];
		}

		if (m < n) {
			cout <<arr[m-1]+t<<' '<< 1 << '\n';
		} else {
			r = m % n;
			q = m / n;
			p = -1;
			if (r > 0) {
				p = arr[r-1] + 2 * t;
				++q;
			}
			for (int i = r + n-1; i < m; i += n) {
				p = max(p, arr[i]);
				p += 2 * t;
			}
			cout << p - t << ' ' << q << '\n';
		}
		
	}
	return 0;
}