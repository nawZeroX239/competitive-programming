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

vector<char> opr;
vector<int> vi;

long long minx(int i) {
	long long r = vi[i];
	for (int j = i; j < opr.size(); ++j) {
		if (opr[j] == '*') {
			r = r * vi[j + 1];
		} else {
			return r + minx(j + 1);
		}
	}

	return r;
}

long long maxx(int i) {
	long long r = vi[i];
	for (int j = i; j < opr.size(); ++j) {
		if (opr[j] == '*') {
			return r * maxx(j + 1);
		} else {
			r += vi[j + 1];
		}
	}

	return r;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int T, n, m, k, x;
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		n = s.length();
		vi.clear();
		opr.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i] == '*' || s[i] == '+') {
				opr.push_back(s[i]);
			} else {
				x = s[i] - '0';
				for(k = i + 1, m = 1; k < n && s[k] >= '0' && s[k] <= '9'; ++k) {
					x = pow(10, m++) * x + s[k] - '0';
				}
				i = k - 1;
				vi.push_back(x);
			}
		}

		cout << "The maximum and minimum are "<<maxx(0)<<" and "<<minx(0)<<'.' << '\n';
	}

	return 0;
}