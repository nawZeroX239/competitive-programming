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
const int N = 'Z' - 'A' + 1;

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

bool isVow(int ch) {
	ch += 'A';
	return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int k, n, m, T, tc=1, x, y, con, vow;
	string ans, odd, even;
	vector<int> v, c;
	vector<vector<int>> vvi(9);
	n = 'Z' - 'A' + 1, k = 0;
	while (k < n) {
		for (int i = 1; i <= 9 && k < n; ++i, ++k) {
			if (!isVow(k)) {
				vvi[i - 1].push_back(k);
			}
		}
	}

	v.push_back('A' - 'A');
	v.push_back('U' - 'A');
	v.push_back('E' - 'A');
	v.push_back('O' - 'A');
	v.push_back('I' - 'A');

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < vvi[i].size(); ++j) {
			c.push_back(vvi[i][j]);
		}
	}

	//for (int i = 0; i < c.size(); ++i) {
	//	cout << char(c[i] + 'A') << '\n';
	//}
	//for (int i = 0; i < v.size(); ++i) {
	//	cout << char(v[i] + 'A') << '\n';
	//}

	cin >> T;
	while (T--) {
		cin >> n;
		x = y = vow = con = 0;
		odd.clear(), even.clear(), ans.clear();
		for (int i = 1; i <= n; ++i) {
			if(i & 1) {
				++vow;
				odd.push_back(char(v[y] + 'A'));
				if (vow == 21) {
					vow = 0;
					++y;
				}
			} else {
				++con;
				even.push_back(char(c[x] + 'A'));
				if (con == 5) {
					con = 0;
					++x;
				}
			}
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		x = y = 0;
		for (int i = 1; i <= n; ++i) {
			if (i & 1) {
				ans.push_back(odd[x++]);
			} else {
				ans.push_back(even[y++]);
			}
		}
		cout << "Case " << tc++ << ": " << ans << '\n';
	}
	return 0;
}