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
//#include <cmath>
//#include <climits>
//#include <bitset>
//#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 30;

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

pair<int, int> tm[100], s[100];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n, m, f, g;
	bool ok;
	while (cin >> m >>n) {
		if (m == 0 && n == 0) break;
		vector<vector<int>> sol(m);
		for (int i = 0; i < m; ++i) {
			cin >> tm[i].first;
			tm[i].second = i;
		}
		for (int i = 0; i < n; ++i) {
			cin >> s[i].first;
			/*--sz[i].first;*/
			s[i].second = i;
		}
		sort(tm, tm + m, greater<pair<int, int>>());
		sort(s, s + n, greater<pair<int, int>>());
		f = n, ok = true;
		for (int i = 0; i < m; ++i) {
			if (f < tm[i].first) {
				ok = false;
				break;
			}
			g = tm[i].first;
			for (int j = 0; j < n && g > 0; ++j) {
				if (s[j].first <= 0) continue;
				--g;
				sol[tm[i].second].push_back(s[j].second);
				--s[j].first;
				if (s[j].first == 0) --f;
			}
			if (g) {
				ok = false;
				break;
			}
		}
		cout << ok << '\n';
		if (ok) {
			for (int i = 0; i < m; ++i) {
				// sort(sol[i].begin(), sol[i].end());
				cout << sol[i][0] + 1;
				for (int j = 1; j < sol[i].size(); ++j) {
					cout << ' ' << sol[i][j]+1;
				}
				cout << '\n';
			}
		}
	}

	return 0;
}