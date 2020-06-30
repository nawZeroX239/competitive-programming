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
#define N 1000001
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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int  n, sz;
	cin >> n;
	sz = n/2;
	if (sz == 0 ||(sz%2 && n%2==0) || (sz%2==0 && n%2)) cout << "NO\n";
	else {
		cout << "YES\n";
		vector<int> P, Q;
		int lo = sz;
		int hi = sz + 1;
		while (lo > 0) {
			if (P.size() < sz) {
				P.push_back(lo);
				P.push_back(hi);
			} else {
				Q.push_back(lo);
				Q.push_back(hi);
			}
			--lo;
			++hi;
		}

		if (n&1) {
			if (P.size() < Q.size()) P.push_back(hi);
			else Q.push_back(hi);
		}

		cout << P.size() << '\n';
		auto it1 = P.begin();
		auto it2 = Q.begin();
		if (it1 != P.end()) {
			cout << *it1;
			++it1;
			for (; it1 != P.end(); ++it1) {
				cout << ' ' << *it1;
			}
			cout << '\n';
		}
		cout << Q.size() << '\n';
		if (it2 != Q.end()) {
			cout << *it2;
			++it2;
			for (; it2 != Q.end(); ++it2) {
				cout << ' ' << *it2;
			}
			cout << '\n';
		}
	}
}