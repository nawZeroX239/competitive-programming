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
const int N = 500000;

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
	if (left.first == right.first) {
		return left.second < right.second;
	}
	return left.first < right.first;
}

bool lb_pred(const pair<int, int>& left, const int right) {
	return left.first < right;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, k, l, x, y;
	bool ok;
	while (cin >> n) {
		if (n == 0) break;
		vector<pair<int, int>> a(n);
		vector<pair<int, int>>::iterator it;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a.begin(), a.end(), sort_pred);
		//for (int i = 0; i < n; ++i) {
		//	cout << a[i].first <<' '<< a[i].second << '\n';
		//}

		k = 0, ok = true;
		while (k < n) {
			x = a[k].first;
			y = a[k].second;
			it = lower_bound(a.begin(), a.end(), y, lb_pred);
			if (it == a.end() || it->first > y) {
				ok = false;
				break;
			}
			m = it - a.begin();
			while (m < n && a[m].second != x && a[m].first == y) {
				++m;
			}
			if (m >= n) {
				ok = false;
				break;
			}
			// cout <<y<< " found at " << m << '\n';
			for (k = k + 1; k < n && a[k].first == x; ++k) {
				if (a[k].second == y) {
					if (m + 1 >= n || a[m+1].first > y || a[m+1].second != x) {
						ok = false;
						break;
					}
					++m;
				} else {
					y = a[k].second;
					//cout << "search key changed to "<< y << '\n';
					it = lower_bound(a.begin(), a.end(), y, lb_pred);
					if (it == a.end() || it->first > y) {
						ok = false;
						break;
					}
					m = it - a.begin();
					while (m < n && a[m].second != x && a[m].first == y) {
						++m;
					}
					if (m >= n) {
						ok = false;
						break;
					}

				}
			}

		}
		if (ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	
	}

}