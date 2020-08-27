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
const int N = 20;

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
pair<int, int> a[N];

bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	// choose sequence which result in smallest time
	return left.first + max(left.second, right.first) + right.second <
		right.first + max(left.first, right.second) + left.second;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n, ans, t;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
		}
		for (int i = 0; i < n; ++i) {
			cin >> a[i].second;
		}
		sort(a, a + n, sort_pred);
		t = ans = 0;
		for (int i = 0; i < n; ++i) {
			t += a[i].first;
			ans = max(ans + a[i].second, t + a[i].second);
			//ans = max(ans, t1 + a[i].second);
			//t1 = max(t0 + a[i].second, t1 + a[i].second);
		}
		cout << ans << '\n';
	}
	return 0;

}