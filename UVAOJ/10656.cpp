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
	
	int T, n, m;
	while (cin >> n) {
		if (n == 0) break;
		vector<int> vi;
		for (int i = 0; i < n; ++i) {
			cin >> m;
			if (m) vi.push_back(m);
		}
		if (vi.size()) {
			cout << vi[0];
			for (int i = 1; i < vi.size(); ++i) {
				cout << ' ' << vi[i];
			}
			cout << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}