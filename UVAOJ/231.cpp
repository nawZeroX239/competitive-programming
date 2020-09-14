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

bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.second > right.second;
}

bool lb_pred(const pair<int, int>& left, const int right) {
	return left.first < right;
}



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int tc = 1, h, n, m, pos;
	while (true) {
		vector<int> vi;
		while (cin >> h) {
			if (h == -1) {
				break;
			}
			vi.push_back(h);
		}

		if (vi.size() == 0) break;
		if (tc > 1) cout << '\n';
		//cout << "vi ";
		//for (int i = 0; i < vi.size(); ++i) {
		//	cout << vi[i] << ' ';
		//}
		//cout << '\n';

		reverse(vi.begin(), vi.end());
		n = vi.size();
		vector<int> L(n, 0);
		m = 0;
		for (int i = 0; i < n; ++i) {
			pos = upper_bound(L.begin(), L.begin() + m, vi[i]) - L.begin();
			L[pos] = vi[i];
			if (pos == m) {
				m = pos + 1;
			}
		}
		
		cout << "Test #" << tc++<<':' << '\n';

		cout << "  maximum possible interceptions: "<<m << '\n';
	}

	return 0;
}