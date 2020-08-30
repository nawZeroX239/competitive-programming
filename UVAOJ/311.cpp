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
#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <ctime>
#include <climits>
#include <cmath>
//#include <bitset>
//#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 6;

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

int a[7];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int T, n, m, ans, f, g;
	bool br;
	while (true) {
		br = true;
		for (int i = 1; i <= 6; ++i) {
			cin >> a[i];
			br = br && a[i] == 0;
		}
		if (br) break;
		ans = a[6];
		if (a[5] > 0) {
			ans += a[5];
			a[1] -= 11 * a[5];
		}

		if (a[4] > 0) {
			ans += a[4];
			f = a[4]*5;
			if(f <= a[2]) {
				a[2] -= f;
			}else {
				a[1] -= 4 * (f - a[2]);
				a[2] -= f;				
			}
		}

		if (a[3] > 0) {
			m = a[3] % 4;
			ans += a[3]/4 +(m>0);
			if (m) {
				if (a[2] > 0) {
					g = (m == 1 ? 5 : (m == 2 ? 3 : 1));
					if(g > a[2]) {
						a[1] -= 36 - 9 * m - 4 * a[2];

						a[2] = 0;
					} else {
						a[1] -= 36 - 9 * m - 4 * g;

						a[2] -= g;

					}
				} else {
					a[1] -= 36 - 9 * m;
				}
			}
		}

		if (a[2] > 0) {
			m = a[2] % 9;
			ans += a[2] / 9 + (m>0);
			if (m) {
				a[1] -= 36 -4 * m;
			}
		}

		if (a[1] > 0) {
			m = a[1] % 36;
			ans += a[1] / 36 + (m > 0);
		}
		cout << ans << '\n';
	}
	return 0;
}