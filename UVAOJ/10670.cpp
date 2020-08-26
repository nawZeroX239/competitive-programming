#include <iostream>
//#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
//#include <unordered_set>
#include <vector>
//#include <list> 
//#include <string>
//#include <iterator> 
//#include <iomanip>
//#include <deque>
//#include <array>
//#include <forward_list>
//#include <queue>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <ctime>
#include <climits>
//#include <bitset>
//#include <numeric>
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

struct e {
	string s;
	int c;
};

bool sort_pred(const e& left, const e& right) {
	if (left.c == right.c) {
		return left.s < right.s;
	}
	return left.c < right.c;
}


e r[N];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int T, tc, a, b, k, l, m, n, h;
	string s;
	cin >> T;
	for (tc = 1; tc <= T; ++tc) {
		cin >> n >> m >> l;
		
		for (int i = 0; i < l; ++i) {
			cin >> s;
			for (int j = 0; j < s.length(); ++j) {
				if (s[j] == ':' || s[j] == ',') {
					s[j] = ' ';
				}
			}
			stringstream ss(s);
			ss >> r[i].s >> a >> b;
			k = n, r[i].c = 0;
			while (k > m) {
				h = k / 2;
				//  cout <<"k: "<<k<<" h: "<< h << '\n';
				// if (k & 1) y = (h + 1) * a;
				if (h < m) {
					r[i].c += (k - m) * a;
					break;
				} else {
					if (h * a < b) {
						r[i].c += h * a;
						k -= h;
					} else {
						r[i].c += b;
						k /= 2;
					}
				}
			}
		}
		sort(r, r + l, sort_pred);
		cout << "Case " << tc << '\n';
		for (int i = 0; i < l; ++i) {
			cout << r[i].s << ' ' << r[i].c << '\n';
		}
		
	}


	return 0;
}