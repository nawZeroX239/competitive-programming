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

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int T, tc, n, m;
	string ln;
	getline(cin, ln);
	T = toInt(ln);
	while (T--) {
		getline(cin, ln);
		n = toInt(ln);
		map<string, int> mp;
		vector<int> vi(n);
		vector<string> s(n);
		for (int i = 0; i < n; ++i) {
			getline(cin, ln);
			mp[ln] = i;
			s[i] = ln;
		}

		for (int i = 0; i < n; ++i) {
			getline(cin, ln);
			vi[i] = mp[ln];
		}

		for (m = n - 2; m >= 0; --m) {
			if (vi[m] > vi[m + 1]) break;
		}
		while (m >= 0) {
			cout << s[vi[m--]] << '\n';
		}

		cout << '\n';
	}

	return 0;
}