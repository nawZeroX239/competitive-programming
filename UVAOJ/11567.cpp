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

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	long long n, ans, p, q;
	while (cin >> n) {
		ans = 0;
		while (n > 0) {
			if (n < 4) {
				ans += n;
				break;
			}
			++ans;
			if (n & 1) {
				p = (n - 1) / 2;
				q = (n + 1) / 2;
				if (q%2) {
					n = n - 1;
				} else {
					n = p % 2 ? n + 1 : n - 1;
				}
			} else {
				n /= 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}